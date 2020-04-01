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

inline li solve(vpli *g,li *sn,unordered_set<li>& sk,li n,li k){
	
	
	li mindist=INT_MAX;
	REP(i,0,k){
	vli dist(n+1,INT_MAX);
	int vis[n+1];
	memset(vis,0,sizeof vis);
	priority_queue<pli,vector<pli>,greater<pli> >Q;
	
	Q.push({0,sn[i]});
	dist[sn[i]]=0;
	while(!Q.empty()){
		pli top = Q.top();
		Q.pop();
		li u = top.second;
		li du = top.first;
		if(u!=sn[i] && sk.find(u)!=sk.end())
			mindist = min(mindist,dist[u]);
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:g[u]){
			li v = x.second;
			li w = x.first;
			if(!vis[v] && dist[v]>w+dist[u]){
				dist[v]=w+dist[u];
				Q.push({dist[v],v});
			}
		}
	}
	
	}
	return mindist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


	li n,m,k;
	cin>>n>>m>>k;
	li sn[k];
	unordered_set<li>sk;
	REP(i,0,k){
		cin>>sn[i];
		sk.insert(sn[i]);
	}
	vpli g[n+1];
	REP(i,0,m){
		li u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	
	cout<<solve(g,sn,sk,n,k)<<"\n";
}

