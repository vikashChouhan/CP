#include<bits/stdc++.h>
using namespace std;

#define LI long int
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

void bfs(VEC(LI) *graph, LI u,int *vis,LI maxDist,LI dist,set<LI>&secure)
{
	queue<PAIR(LI,LI)>Q;
	Q.push({u,0});
	
	while(!Q.empty())
	{
		PAIR(LI,LI) top = Q.front();
		LI x = top.first;
		LI dist = top.second;
		Q.pop();
		if(dist > maxDist || vis[x])
			continue;
		
		secure.insert(x);
		vis[x] = 1;
		for(auto &y: graph[x])
			Q.push({y,dist+1});
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	
	while(t--)
	{
		LI N, R, M;
		cin >> N >> R >> M;
		
		VEC(LI) graph[N+1];
		LI u,v;
		for(LI i=0; i<R; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		LI city, strength;
		set<LI>secure;
		
		int vis[N+1] = {0};
		set<PAIR(LI,LI)> loc;
		for(int i=0; i<M; i++)
		{
			cin >> city >> strength;
			loc.insert({strength,city});
		}
		
		for(auto x:loc)
			bfs(graph,x.second,vis,x.first,0,secure);
			
		if(secure.size()==N)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}


