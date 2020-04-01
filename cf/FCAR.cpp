#include<bits/stdc++.h>
using namespace std;

#define li long int 
#define vli vector<li>
#define pli pair<li,li>
#define vpli vector<pli>
#define ppli pair<li,pli>
int main()
{
	li n,r;
	cin>>n>>r;
	li h[n+1],c[n+1];
	for(li i=1;i<=n;i++)cin>>h[i];
	for(li i=1;i<=n;i++)cin>>c[i];
	
	vli g[n+1];
	for(li i=0;i<r;i++){
		li u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	li dist[n+1][2];
	for(li i=0;i<n+1;i++)
	    dist[i][0]=dist[i][1]=INT_MAX;
	dist[1][0]=c[1];
	dist[1][1]=c[1];
	priority_queue<ppli,vector<ppli>,greater<ppli> > Q;
	Q.push({c[1],{1,-1}});
	Q.push({c[1],{1,1}});
	
	while(!Q.empty()){
		auto top = Q.top();
		Q.pop();
		li u = top.second.first;
		li d = top.first;
		li dir = top.second.second;
		if(u==n) break;
		
		for(auto v:g[u]){
			if(dir==1){
				if(h[v]<=h[u] && dist[v][0]>c[u]+d){
					dist[v][0]=c[u]+d;
					Q.push({dist[v][0],{v,-1}});
				}
				if(h[v]>=h[u] && dist[v][1]>d){
					dist[v][1]=d;
					Q.push({dist[v][1],{v,1}});
				}
			}
			if(dir==-1){
				if(h[v]>=h[u] && dist[v][1]>c[u]+d){
					dist[v][1]=c[u]+d;
					Q.push({dist[v][1],{v,1}});
				}
				if(h[v]>=h[u] && dist[v][0]>d){
					dist[v][0]=d;
					Q.push({dist[v][0],{v,-1}});
				}
			}
		}
	}
	li ans  = min(dist[n][0],dist[n][1]);
	if(ans!=INT_MAX)
		cout<<ans;
	else
		cout<<"-1";
}
