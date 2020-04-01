#include<bits/stdc++.h>

using namespace std;
#define li long int
#define ll long long
#define pi pair<int,int>
#define pli pair<long int,long int>
#define vi vector<int>
#define vli vector<long int>
#define vll vector<long long>
#define vpi vector<pair<int,int> >
#define vpli vector<pair<long int,long int> >
#define MOD 1000000007
#define ll long long
#define ull unsigned long long 
#define REP(i,init,n) for(li i=init;i<n;i++)
#define INF 0x3f3f3f3f
template<class T>
inline T MODIT(T x){ return (x%MOD+MOD)%MOD;}


li DFS(vli *graph,li u,int *visited,li *parent,li p,int *all2degree)
{
	li edges=0;
	edges += graph[u].size();
	if(edges!=2 && *all2degree)
		*all2degree=0;
		
	visited[u]=1;
	
	parent[u]=p;
	for(auto x:graph[u])
	{
		if(!visited[x])
		{
			edges += DFS(graph,x,visited,parent,p,all2degree);
			visited[x]=1;
		}
	}
	return edges;
}
void getConnectedComponents(vli *graph,li n,vector<pair<li,pli> > &cmp,li *Kset,li *parent)
{
	int visited[n+1]={0};
	int all2degree=1;
	li k=0;
	for(li i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			li edges = DFS(graph,i,visited,parent,k,&all2degree)/2;
			pair<li,pli> pp = {i,{edges,all2degree}};
			cmp.push_back(pp);
			if(pp.second.first%2==0)
				Kset[cmp.size()-1]=1;
			k++;
			all2degree=1;
		}
	}
}

void setForOddCycle(vli *graph,li u,li *parent,int *visited,li *cnt)
{
	parent[u]=*cnt;
	visited[u]=1;
	*cnt+=1;
	for(auto x:graph[u])
	{
		if(!visited[x])
			setForOddCycle(graph,x,parent,visited,cnt);
	}
}
int setForOddDegree(vli *graph,li u,li *parent,int *visited)
{
	
	if(graph[u].size()&1)
	{
		parent[u]=2;
		return -1;
	}
	visited[u]=1;
	for(auto x:graph[u])
	{
		if(!visited[x])
		{
			int temp=setForOddDegree(graph,x,parent,visited);
			if(temp==-1)
				return -1;
		}
	}
	return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
    	li n,m;
    	cin>>n>>m;
    	vli graph[n+1];
    	for(li i=0;i<m;i++)
    	{
    		li u,v;
    		cin>>u>>v;
    		graph[u].push_back(v);
    		graph[v].push_back(u);
		}
		if(m%2==0)
		{
			cout<<1<<"\n";
			REP(i,0,n)
				cout<<1<<" ";
			cout<<"\n";
			continue;
		}
		vector<pair<li,pli> > cmp;
		li Kset[n+1];
		memset(Kset,-1,sizeof(Kset[0])*(n+1));
		li parent[n+1]={-1};
		getConnectedComponents(graph,n,cmp,Kset,parent);
		
		/*for(li i=0;i<cmp.size();i++)
		cout<<cmp[i].first<<" e="<<cmp[i].second.first<<" oc="<<cmp[i].second.second<<"\n";
		*/
		li oddidx=-1,oddcnt=0;
		for(li i=0;i<cmp.size();i++)
		{
			if(cmp[i].second.first&1)
				oddcnt++;
		}
		//cout<<"oddcnt="<<oddcnt<<"\n";
		if(oddcnt>1)
		{
			for(li i=0;i<cmp.size();i++)
			{
				if(cmp[i].second.first&1)
				{
					if((!cmp[i].second.second && oddidx==-1) || (oddcnt==1 && oddidx==-1))
						oddidx=i;
					else
						Kset[i]=1;
					
					oddcnt--;
				}
				else
					Kset[i]=1;
			}
		}
		else
		{
			for(li i=0;i<cmp.size();i++)	
				if(cmp[i].second.first&1 && oddidx==-1)
				{
					oddidx=i;
				}
				else
					Kset[i]=1;
		}
		//cout<<"oddidx="<<oddidx<<"\n";
		li NoKsets=0;
		for(li i=1;i<=n;i++)
		{
			parent[i] = Kset[parent[i]];
			if(parent[i]==1)
				NoKsets=1;
		}
		if(NoKsets==0)
			NoKsets++;
		int visited[n+1]={0};
		if(cmp[oddidx].second.second)
		{
			setForOddCycle(graph,cmp[oddidx].first,parent,visited,&NoKsets);
			//NoKsets--;
		}
		else
		{
			setForOddDegree(graph,cmp[oddidx].first,parent,visited);
			//NoKsets++;
		}
		
		cout<<*max_element(parent+1,parent+n+1)<<"\n";
		for(li i=1;i<=n;i++)
			if(parent[i]==-1)
				cout<<1<<" ";
			else
				cout<<parent[i]<<" ";
		cout<<"\n";
		
	}
    
}
