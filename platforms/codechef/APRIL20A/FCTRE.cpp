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

#define vpi VEC(PAIR(LI,LI))
#define MAX2 1000001
#define MAX 100001

LI spf[MAX2];
VEC(LI) path;
LI height[MAX], entry[MAX], parent[MAX];
LI tree[4*MAX];

void sieve()
{
	spf[1] = 1;
	for(LI i=2; i<MAX2; i++)
	{
		if(spf[i]==0)
		{
			spf[i] = i;
			for(LI j=2*i; j<MAX2; j+=i)
				spf[j] = i;
		}
	}
}

void dfs(VEC(LI) *graph, LI u, LI h,VEC(LI) &arr, unordered_map<LI,LI>* factors)
{
	entry[u] = path.size();
	path.emplace_back(u);
	height[u] = h;
	
	for(auto &x: graph[u])
	{
		if(x == parent[u]) continue;
		factors[x] = factors[u];
		LI temp = arr[x];
		while(temp!=1)
		{
			factors[x][spf[temp]]++;
			temp/=spf[temp];
		}
		
		parent[x] = u;
		dfs(graph, x, h+1, arr, factors);
		path.emplace_back(u);
	}
}

void build(LI i, LI s, LI e)
{
	if(s==e) tree[i] = path[s];
	else
	{
		LI m = (s+e)/2;
		build(2*i, s, m);
		build(2*i+1, m+1, e);
		if(height[tree[2*i]] < height[tree[2*i+1]])
			tree[i] = tree[i*2];
		else
			tree[i] = tree[2*i+1];
	}
}

LI query(LI i, LI s, LI e, LI l, LI r)
{
	if(s>e || e<l) return -1;
	if(s==l && e==r)
		return tree[i];
	
	LI m = (s+e)/2;
	if(r<=m) return query(2*i, s, m, l, r);
	else if(l>m) return query(2*i+1, m+1, e, l, r);
	else
	{
		LI left = query(2*i, s, m, l, m);
		LI right = query(2*i+1, m+1, e, m+1, r);
		if(height[left]<height[right])
			return left;
		else
			return right;
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
		LI N; cin >> N;
		
		VEC(LI) graph[N+1];
		LI u,v;
		for(LI i=0; i<N-1; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		VEC(LI) arr(N+1);
		for(LI i=1; i<=N; i++) cin >> arr[i];
		
		unordered_map<LI,LI> factors[N+1];
		
		path.clear();
		memset(height,-1,sizeof height);
		memset(entry,-1,sizeof entry);
		memset(parent,0,sizeof parent);
		
		LI temp = arr[1];
		while(temp!=1)
		{
			factors[1][spf[temp]]++;
			temp/=spf[temp];
		}
		dfs(graph,1,0,arr,factors);
		build(1, 0, path.size()-1);
		
		
		LI q;
		cin >> q;
		while(q--)
		{
			cin >> u >> v;
			if(entry[u]>entry[v])
			{
				LI temp = u;
				u = v;
				v = temp;
			}
			
			LI lca;
//			cout << "lca="<<lca << endl;
			unordered_map<LI,LI> res;
			
			if(u==v)
			{
				for(auto &x: factors[u])
					res[x.first] = x.second-factors[parent[u]][x.first];
			}
			else
			{
				lca = query(1, 0, path.size()-1, entry[u], entry[v]);
				if(lca == u)
				{
					res = factors[v];
					for(auto &x: factors[parent[u]])
						res[x.first]-= x.second;
				}
				else
				{
					res = factors[u];
					for(auto &x: factors[v])
						res[x.first]+=x.second;
					for(auto &x: factors[lca])
						res[x.first] -= 2*x.second;
					LI temp = arr[lca];
					while(temp!=1)
					{
					    res[spf[temp]]++;
					    temp/=spf[temp];
					}
				}
			}
			
			LI ans = 1;
			for(auto &x: res)
			{
				ans = (ans * (x.second+1))%MOD;
		    }
			cout << ans << "\n";
		}
		
//		for(LI i=1; i<=N; i++)
//		{
//			cout << "\ni="<<i<<endl;
//			for(auto &x: factors[i])
//				cout << "("<<x.first<<","<<x.second<<"), ";
//			cout << "\n";
//		}
	}
	
	return 0;
}


