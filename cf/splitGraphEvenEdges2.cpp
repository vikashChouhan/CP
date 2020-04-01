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

li oddvertex=0;
li DFS(vli *graph,li u,int *visited,li *parent,li p)
{
	li edges=0;
	edges = graph[u].size();
	if(edges&1 && oddvertex==0)
		oddvertex=u;
	
	parent[u]=p;
	visited[u]=1;
	for(auto x:graph[u])
	{
		if(!visited[x])
		{
			edges+= DFS(graph,x,visited,parent,p);
		}
	}
	return edges;
}
void getConnectedComponents(vli *graph,li n,li *Kset)
{
	int visited[n+1]={0};
	int k=1;

	for(li i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			li edges = DFS(graph,i,visited,Kset,k)/2;
			cout<<edges<<" "<<i<<"\n";
			if(edges&1 && oddvertex!=0)
			{
				
				Kset[oddvertex]=2;
				return;
			}
			oddvertex=0;
		}
	}
	
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
		li Kset[n+1];
		memset(Kset,-1,sizeof(Kset[0])*(n+1));
		getConnectedComponents(graph,n,Kset);
		
		cout<<2<<"\n";
		for(li i=1;i<n+1;i++)
			if(Kset[i]==-1)
				cout<<1<<" ";
			else
				cout<<Kset[i]<<" ";
		cout<<"\n";
	}
    
}
