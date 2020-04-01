#include<bits/stdc++.h>
using namespace std;

#define li long int
#define vli vector<li>
inline void dfs(vli *graph,li node,li count,li &maxcount,li &x,li *visited)
{
	visited[node]=1;
	count++;
	for(auto y:graph[node])
	{
		if(!visited[y])
		{
			if(maxcount<count+1)
			{
				maxcount = count+1;
				x = y;
			}
			dfs(graph,y,count,maxcount,x,visited);
		}
	}
}
inline li diameter(vli *graph,li n)
{
	li ans =INT_MIN;
	li x,visited[n+1]={0};
	dfs(graph,1,0,ans,x,visited);
	
	memset(visited,0,sizeof(visited[0])*(n+1));
	
	li temp;
	dfs(graph,x,0,ans,temp,visited);
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		li n;
		cin>>n;
		vli graph[n+1];
		for(li i=0;i<n-1;i++)
		{
			li x,y;
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		
		li ans = diameter(graph,n);
		cout<<ans/2<<"\n";
	}
}
