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

void detectbridge(VEC(int) *graph,int u,int p,int *vis,int *tms,int *low,int ctms,auto &bridges)
{
	tms[u] = low[u] = ctms++;
	vis[u] = 1;
	for(auto x:graph[u])
	{
		if(x==p) continue;
		if(vis[x])
			low[u] = min(low[u],tms[x]);
		else
		{
			detectbridge(graph,x,u,vis,tms,low,ctms,bridges);
			low[u] = min(low[u],low[x]);
			if(low[x] > tms[u])
				bridges.push_back({min(u,x),max(u,x)});
				
		}
	}
}
void getbridges(VEC(int) *graph,int n,auto &bridges)
{
	int tms[n+1] = {0};
	int low[n+1] = {0}, vis[n+1] = {0};
	int ctms;
	for(int i=1; i<=n; i++)
		if(!vis[i])
			detectbridge(graph,i,-1,vis,tms,low,ctms,bridges);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	int k = 1;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		
		VEC(int) graph[n+1];
		for(int i=0; i<m; i++)
		{
			int x,y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		
		VEC(PAIR(LI,LI)) bridges;
		getbridges(graph,n,bridges);
		
		cout << "Caso #" << k << "\n";
		if(bridges.size())
		{
			cout << bridges.size() << "\n";
			sort(bridges.begin(),bridges.end());
			for(auto x: bridges)
			{	
				cout << x.first << " " << x.second << "\n";
			}
		}
		else
			cout << "Sin bloqueos\n";
		k++;
	}

	return 0;
}


