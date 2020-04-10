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

#define MAX 100002
#define MAX2 1000001

LI spf[MAX2+1];
unordered_map<LI,LI> factors[MAX2+1];
VEC(LI) path, prime;
LI height[MAX], vis[MAX], entry[MAX], parent[MAX];

void dfs(VEC(LI) *graph, LI u, LI h)
{
	entry[u] = path.size();
	path.emplace_back(u);
	height[u] = h;
	vis[u] = 1;
	
	for(auto &v: graph[u])
	{
		if(!vis[v])
		{
			parent[v] = u;
			dfs(graph,v,h+1);
			path.emplace_back(u);
		}
	}
}

void process(VEC(LI)* graph)
{
	memset(vis,0,sizeof vis);
	memset(entry,0,sizeof entry);
	memset(parent,-1,sizeof entry);
	memset(height,0,sizeof height);
	path.clear();
	dfs(graph,1,1);
	
	
	
}
void getf(LI n)
{
	if(!factors[n].empty() || n==1) return;
	LI x = n;
    while(x!=1)
    {
        factors[n][spf[x]]++;
        x/=spf[x];
    }
}

void sieve()
{
	bitset<MAX2> comp;
	spf[1] = 1;
	for(LI i=2; i<MAX2; i++)
	{
	    if(comp[i]==0)
	    {
	    	spf[i]=i;
	    	prime.emplace_back(i);
	        for(LI j=0; j<prime.size() && i*prime[j]<MAX2; j++)
	    	{
	    		comp[i*prime[j]] = 1;
	    		spf[i*prime[j]] = i;
	    		if(i%prime[j]==0) break;
			}
	    }
	}
	
}

void sqdecomp(unordered_map<LI,LI> *f, VEC(LI) &arr)
{
	LI size = sqrt(path.size());
	LI low,high,blk=0;
	
	low = 0;
	high = size;
	
	unordered_map<LI,LI> cnt;
	while(low<path.size())
	{
		
		for(LI i=low; i<high; i++)
		{
			getf(arr[path[i]]);
			if(i==low) 
				f[blk] = factors[arr[path[i]]];
			else if(cnt[arr[path[i]]]==0)
			{
				for(auto &it: factors[arr[path[i]]])
					f[blk][it.first] += it.second;
			}
			else
			{
				for(auto &it: factors[arr[path[i]]])
					f[blk][it.first] -= it.second;
			}
			
			cnt[arr[path[i]]]++;
		}
		blk++;
		low = blk*size;
		high = low+size;
		if(high>path.size()) high = path.size();
	}
}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	sieve();
	int t;
	cin >> t;
	while(t--)
	{
		LI N;
		cin >> N;
		
		VEC(LI) graph[N+1];
		LI u,v;
		for(LI i=0; i<N-1; i++) 
		{
			cin >> u >> v;
			graph[u].emplace_back(v);
			graph[v].emplace_back(u);
		}
		
		VEC(LI) arr(N+1);
		for(LI i=1; i<=N; i++) cin >> arr[i];
		
		
		process(graph);
		unordered_map<LI,LI> f[(long)sqrt(path.size())];
		sqdecomp(f,arr);
		
		LI Q;
		cin >> Q;
		while(Q--)
		{
			cin >> u >> v;
			LI l,r;
			l = min(entry[u],entry[v]);
			r = min(entry[u],entry[v]);
			unordered_map<LI,LI>flr;
			
			LI ans = 1;
			for(auto &x: flr)
				ans = (ans * (x.second+1))%MOD;
			cout << ans << "\n";
		}
	}

	return 0;
}


