#include<bits/stdc++.h>
using namespace std;

#define li long int
#define pli pair<li,li>
#define ppli pair<li,pli>
#define INF 999999999

bool bfs(vector<li>*g,li *parent,set<ppli> &s,li st,li t)
{
	queue<pli>Q;
	Q.push({st,0});
	
	li visited[t+1]={0};
	li last=-1,slast=-1;
	while(!Q.empty())
	{
		auto u = Q.front();
		Q.pop();
		
		
		last = u.second;
		slast = parent[last];
	
		if(s.find({slast,{last,u.first}})!=s.end())
			continue;
		
		if(u.first==t) return true;
		visited[u.first]=1;
		for(auto x:g[u.first])
		{
			if(!visited[x])
			{
				Q.push({x,u.first});
				parent[x]=u.first;
				
				if(x==t && s.find({u.second,{u.first,x}})==s.end())
				{
					parent[x]=u.first;
					parent[u.first]=u.second;
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	li n,m,k;
	cin>>n>>m>>k;
	
	vector<li> g[n+1];
	for(li i=0;i<m;i++)
	{
		li u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	
	set<ppli>s;
	for(li i=0;i<k;i++)
	{
		li x,y,z;
		cin>>x>>y>>z;
		s.insert({x,{y,z}});
	}
	
	li parent[n+1]={0};

	if(bfs(g,parent,s,1,n))
	{
		vector<li>path;
		for(li v=n;v!=0;v=parent[v])
			path.push_back(v);
		
		cout<<path.size()-1<<"\n";
		for(li i=path.size()-1;i>0;i--)
			cout<<path[i]<<" ";
		cout<<path[0];
	}
	else	
		cout<<"-1";
	
}
