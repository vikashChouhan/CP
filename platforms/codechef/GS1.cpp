#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007
#define INF 1000000000000000000ll

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

void updateDist(VEC(LI) *graph,LI hos, LL *dist, LI N)
{
	int vis[N+1]={0};
	queue<LI>Q;
	Q.push(hos);
	dist[hos] = 0;
	
	LI nearestHos = -1;
	while(!Q.empty())
	{
		LI u = Q.front();
		Q.pop();
		
		if(vis[u]) continue;
		
		vis[u] = 1;
		for(auto &x: graph[u])
		{
			if(!vis[x] && dist[x] > dist[u]+1)
			{
				dist[x] =  dist[u] + 1;
				Q.push(x);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);


	LI N, M;
	cin >> N >> M;
	
	VEC(LI) graph[N+1];
	LI u,v;
	for(LI i=0; i<M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	LI K;
	cin >> K;
	LL dist[N+1];
	for(LI i=0; i<=N; i++) dist[i] = INF;
	
	for(LI i=0; i<K; i++)
	{
		LI x;
		cin >> x;
		
		updateDist(graph,x,dist,N);
	}
	
	LI q;
	cin >> q;
	while(q--)
	{
		LI loc;
		cin >> loc;
		if(dist[loc]==INF)
			cout << "Dead\n";
		else
			cout << dist[loc] << "\n";
	}

	return 0;
}


