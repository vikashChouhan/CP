#include<bits/stdc++.h>
using namespace std;

#define LI long long
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007

template <typename T>
void SWAP(T &_a, T &_b){ T t = _a;_a = _b; _b = t;}

template <typename T>
ostream &operator<<(ostream &stream, const vector<T>& inp_)
{ for(auto &x: inp_)stream << x << " "; stream << "\n";
return stream;}

template <typename T,typename T_>
ostream &operator<<(ostream &stream, const pair<T,T_>& inp_)
{stream << "(" << inp_.first << "," << inp_.second <<") ";
return stream;}

template <typename T>
T GCD(T a, T b)
{T temp;while(b>0){temp = b;b = a%b;a = temp;}
return a;}

typedef PAIR(LI,PAIR(LI,LI)) ppp;

LI findParent(LI x,LI *par)
{
	if(par[x]!=x)
		par[x] = findParent(par[x],par);
	return par[x];
}
LI Krushkal(VEC(ppp) &edges, LI N)
{
	LI nedges = 0,w,u,v;
	LI par[N];
	for(LI i=0; i<N; i++)
		par[i] = i;
		
	LI weights=0;
	sort(edges.begin(),edges.end());
	for(LI i=0; i<edges.size(); i++)
	{
		auto temp = edges[i];
		w = temp.first;
		u = temp.second.first;
		v = temp.second.second;
		
		if(findParent(u,par)!=findParent(v,par))
		{
			par[par[v]] = findParent(u,par);
			weights += w;
			nedges++;
		}
	}
	
	return (nedges==N-1)?weights:-1;
}

LI Dijkstra(VEC(PAIR(LI,LI)) *graph, LI N)
{
	int vis[N] = {0};
	LI dist[N],lastEdge[N];
	for(LI i=0; i<N; i++)
	{
		dist[i] = INT_MAX;	
		lastEdge[i] = 0;
	}
	
	dist[0] = 0;
	priority_queue<PAIR(LI,LI),VEC(PAIR(LI,LI)), greater<PAIR(LI,LI)> >Q;
	Q.push({0,0});
	LI w,u,v,d;
	while(!Q.empty())
	{
		auto top = Q.top();
		Q.pop();

		u = top.second;
		d = top.first;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto x: graph[u])
		{
			v = x.second;
			w = x.first;
			if(!vis[v] && dist[v]>w+d)
			{
				dist[v] = w+d;
				lastEdge[v] = w;
				Q.push({dist[v],v});
			}
			else if(dist[v]==w+d && w < lastEdge[v])
				lastEdge[v] = w;
		}
	}
	
	LI res = 0;
	for(LI i=0; i<N; i++)
		res+=lastEdge[i];

	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	
	while(t--)
	{
		LI N, M;
		cin >> N >> M;
		
		VEC(ppp) edges;
		VEC(PAIR(LI,LI)) graph[N];
		
		int u,v;
		LI w;
		for(LI i=0; i<M; i++)
		{
			cin >> u >> v >> w;
			edges.push_back({w,{u,v}});
			graph[u].push_back({w,v});
			graph[v].push_back({w,u});
		}
		
		LI kweight = Krushkal(edges,N);
		if(kweight==-1)
		{
			cout << "NO\n";
			continue;
		}
		LI dkweight = Dijkstra(graph,N);
		
		//cout << kweight << " " << dkweight << "\n";
		if(kweight == dkweight)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}


