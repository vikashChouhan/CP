#include<bits/stdc++.h>
using namespace std;

#define li long int
#define vli vector<li>

void dfs(vli *graph,li node,int *visited,li &x,li count,li &maxcount)
{
	visited[node]=1;
	for(auto y:graph[node])
	{
		if(!visited[y])
		{
			if(count+1>maxcount)
			{
				maxcount=count+1;
				x = y;
			}
			dfs(graph,y,visited,x,count+1,maxcount);
		}
	}
}
li diameter(vli *graph,li n)
{
	int visited[n+1]={0};
	li ans=INT_MIN;
	li x;
	dfs(graph,1,visited,x,0,ans);
	memset(visited,0,sizeof(visited[0])*(n+1));
	li temp;
	dfs(graph,x,visited,temp,0,ans);
	return ans;
}
int main()
{
	li n;
	cin>>n;
	vli graph[n+1];
	for(li i=0;i<n-1;i++)
	{
		li u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout<<diameter(graph,n)<<"\n";
}
