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

#define MAX 1000002
unordered_map<LI,LI>factors[MAX+1];
int vis[100002];
void preprocess()
{
	
	for(LI i=2; i<=MAX; i++)
	{
		LI temp = i;
		while(!(temp&1)) 
		{
			factors[i][2]++;
			temp/=2;
		}
		for(LI j=3; j*j<=temp; j+=2)
		{
			while(temp%j==0)
			{
				factors[i][j]++;
				temp/=j;
			}
		}
		if(temp>2) factors[i][temp]++;
	}
}


int dfs(VEC(LI) *graph, LI u, LI dest, VEC(LI) &A, unordered_map<LI,LI>&f)
{
	if(u == dest) return 1;
	
	vis[u] = 1;
	for(auto &v: graph[u])
	{
		if(!vis[v])
		{
			if(dfs(graph, v, dest, A, f))
			{
//				cout << u << " ";
				if(f.empty())
					f = factors[A[v]];
				else if(A[v]!=1)
				{
					for(auto &x: factors[A[v]])
						if(f.find(x.first)!=f.end())
							f[x.first] += x.second;
						else
							f[x.first] = x.second;
				}
				return 1;
			}
		}
	}
	
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	preprocess();
	while(t--)
	{
		LI N;
		cin >> N;
		
		VEC(LI) graph[N+1];
		LI u,v;
		for(LI i=0; i<N-1; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		VEC(LI) A(N+1);
		for(LI i=1; i<=N; i++) cin >> A[i];
		
		LI Q;
		cin >> Q;
		unordered_map<LI,LI> f;
		while(Q--) 
		{
			cin >> u >> v;
			memset(vis,0,sizeof(vis));
			f.clear();
			dfs(graph,u,v,A,f);
//			cout << endl;
			LI ans = 1;
			for(auto &x: factors[A[u]])
				if(f.find(x.first)!=f.end())
					f[x.first] += x.second;
				else
					f[x.first] = x.second;
			
//			cout <<endl;	
			for(auto &x: f)
			{
				ans = (ans%MOD * (x.second+1)%MOD)%MOD;
//				cout << x.first << " ";			
			}
//			cout << endl;
			cout << ans <<"\n";
		}
		
	}

	return 0;
}


