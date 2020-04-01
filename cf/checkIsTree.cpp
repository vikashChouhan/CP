#include<bits/stdc++.h>
using namespace std;

#define li long int
#define vli vector<li>

bool dfs(vli *graph,li node,int *visited,li *parent)
{
	visited[node]=1;
	for(auto x:graph[node])
	{
		if(!visited[x])
		{
			parent[x]=node;
			dfs(graph,x,visited,parent);
		}
		else if(parent[node]!=x)
		{
			return false;
		}
	}
	return true;
}
int main()
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
	int visited[n+1]={0};
	li parent[n+1];
	bool tree = dfs(graph,1,visited,parent);
	
	for(li i=1;i<=n;i++)
		if(!visited[i])
		{
			tree=false;
			break;
		}
	if(tree)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
