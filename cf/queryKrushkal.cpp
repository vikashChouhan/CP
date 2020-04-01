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

inline li findParent(li *parent,li x){
	if(parent[x]!=x)
		parent[x] = findParent(parent,parent[x]);
	return parent[x];
}

inline void join(li *parent,li u,li v){
	parent[findParent(parent,v)]=parent[u];
}
li krushkal(set<pair<li,pli> >&edges,li n,map<pli,li>&Tedges,map<pli,li>&marked){
	li parent[n+1];
	REP(i,1,n+1)parent[i]=i;

	li msd=0;
	for(edge:edges){
		li u = edgesecond.first;
		li v = edgesecond.second;
		li w = edgefirst;
		if(findParent(parent,u)!=findParent(parent,v)){
			join(parent,u,v);
			msd += w;
			
			Tedges[{u,v}]=w;
			Tedges[{v,u}]=w;			
		}
	}
	
	return msd;
}

li krushkal(set<pair<li,pli> >&edges,li n,map<pli,li>&Tedges,map<pli,li>&marked){
	li parent[n+1];
	REP(i,1,n+1)parent[i]=i;
	
	li msd=0;
	li cnt=0;
	for(auto edge:edges){
		li u = edge.second.first;
		li v = edge.second.second;
		li w = edge.first;
		if(findParent(parent,u)!=findParent(parent,v)){
			join(parent,u,v);
			msd += w;
			cnt++;			
		}
	}
	for(auto edge:Tedges){
		li u = edge.second.first;
		li v = edge.second.second;
		li w = edge.first;
		if(findParent(parent,u)!=findParent(parent,v)){
			join(parent,u,v);
			msd += w;
			cnt++;			
		}
	}
	
	
	return msd;
}

li krushkal2(set<pair<li,pli> >newedges,)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	li n,m,q;
	cin>>n>>m>>q;
	set<pair<li,pli> > edges;

	REP(i,0,m){
		li u,v,w;
		cin>>u>>v>>w;
		edges.insert({w,{u,v}});
	}
	
	set<pair<li,pli> > Tedges;
	map<pli,li>marked;
	li spw = krushkal(edges,n,Tedges,marked);
	set<pair<li,pli> > newedges;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			li u,v;
			cin>>u>>v;
			newedges.insert({0,{u,v}});
			if(Tedges.find({u,v})!=Tedges.end())
				marked[{u,v}]=1;
			if(Tedges.find({v,u})!=Tedges.end())
				marked[{v,u}]=1;
		}
		else if(type==2){
			li u,v;
			cin>>u>>v;
			newedges.erase({0,{u,v}});
			if(Tedges.find({u,v})!=Tedges.end())
				marked.erase({u,v});
			if(Tedges.find({v,u})!=Tedges.end())
				marked.erase({v,u});
		}
		else{
			if(newedges.empty())
				cout<<spw<<"\n";
			else{
				spw=krushkal2(newedges,Tedges,n,marked)
				cout<<spw<<"\n";
			}
		}
	}
}

