#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>*g,int *T,int u,int v,int n)
{
	*(T + (u*(n+1)+v))=1;
	*(T + (v*(n+1)+u))=1;
	for(auto x:g[v])
	{
		if(*(T + (u*(n+1))+x)==0)
		{
			dfs(g,T,u,x,n);
		}
	}
}
void getTrans(vector<int>*g,int*T,int n)
{
	for(int i=1;i<=n;i++)
	{
	
			dfs(g,T,i,i,n);
		
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>g[n+1];
	for(int i=0;i<m;i++ )
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	int tranCl[n+1][n+1];
	memset(tranCl,0,sizeof(tranCl[0][0])*(n+1)*(n+1));
	getTrans(g,tranCl[0],n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<tranCl[i][j]<<" ";
		cout<<"\n";
	}
}
