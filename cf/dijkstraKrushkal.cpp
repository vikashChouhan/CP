#include<bits/stdc++.h>
using namespace std;

#define li long int 
#define vli vector<li>
#define pli pair<li,li>
#define ppli pair<li,pair<li,li> >
#define vpli vector<pair<li,li> >

li findParent(li *parent,li x)
{
	if(parent[x]!=x)
		parent[x] = findParent(parent,parent[x]);
	
	return parent[x];
}
li join(li *parent,li u,li v)
{
	parent[findParent(parent,v)] = findParent(parent,u);
}
pli krushkal(vpli *g,vector<ppli> &edges,li n)
{
	sort(edges.begin(),edges.end());
	li mindist=0;
	li parent[n+1]={0};
	for(li i=0;i<=n;i++) parent[i]=i;
	
	li cnt=0;
	for(li i=0;i<edges.size();i++)
	{
		li u = edges[i].second.first;
		li v = edges[i].second.second;
		if(findParent(parent,u)!=findParent(parent,v))
		{
			mindist += edges[i].first;
			cnt++;
			join(parent,u,v);
		}
	}
	
	return {mindist,cnt};
}

pli dijkstra(vpli *g,li n)
{
	li visited[n+1]={0};
	vli last_edge(n,INT_MAX);
	li mindist = 0;
	vli dist(n+1,INT_MAX);
	
	priority_queue<ppli,vector<ppli>,greater<ppli> >Q;
	Q.push({0,{0,0}});
	visited[0]=1;
	dist[0]=0;
	last_edge[0]=0;
	
	li cnt=1;
	while(!Q.empty())
	{
		ppli top = Q.top();
		Q.pop();
		li u = top.second.second;
		li w = top.first;
		
		if(visited[u]) continue;
		visited[u]=1;
		for(auto x:g[u])
		{
			if(!visited[x.second])
			{
				if(dist[u]+x.first<dist[x.second])
				{
					last_edge[x.second]=x.first;
					dist[x.second]=x.first+dist[u];
					Q.push({dist[x.second],{last_edge[x.second],x.second}});
					cnt++;
				}
				else if((dist[u]+x.first==dist[x.second] && last_edge[x.second]>x.first))
				{
					last_edge[x.second]=x.first;
					dist[x.second]=x.first+dist[u];
					cnt++;
				}
			}
		}
		
	}
	for(li i=0;i<n;i++)
		if(last_edge[i]!=INT_MAX)
			mindist+=last_edge[i];
		else
			return {-1,-1};
	
	return {mindist,cnt};
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		li n,m;
		cin>>n>>m;
		
		vpli g[n+1];
		vector<ppli> edges;
		for(li i=0;i<m;i++)
		{
			li u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({w,v});
			g[v].push_back({w,u});
			
			edges.push_back({w,{u,v}});
		}
		
		pli d1=krushkal(g,edges,n);
		pli d2=dijkstra(g,n);
		
		if(d1.first==d2.first && d1.second==n-1 && d2.second==n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		
	}
}
