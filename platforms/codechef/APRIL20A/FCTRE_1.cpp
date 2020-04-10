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

LI spf[MAX2];
unordered_map<LI,LI>factors[MAX2];
VEC(LI) path,path2;
LI height[MAX], vis[MAX], entry[MAX], leave[MAX];
LI tree[4*MAX], parent[MAX];

struct node {
	unordered_map<LI,LI>f;
	unordered_set<LI> s;
};

node tree2[4*MAX];

void preprocess()
{
   spf[1] =  1;
   for(LI i=2; i<MAX2; i++)
   {
        if(spf[i]==0)
        {
            spf[i] = i;
            for(LI j=i*2; j<MAX2; j+=i)
                spf[j] = i;
        }
   }
   
   for(LI i=2; i<MAX2; i++)
   {
       LI x = i;
       while(x!=1)
       {
           factors[i][spf[x]]++;
           x/= spf[x];
       }
   }
}

void dfs(VEC(LI) *graph, LI u, LI h)
{
	entry[u] = path.size();
	path.emplace_back(u);
	path2.emplace_back(u);
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
	leave[u] = path.size();
	path2.emplace_back(u);	
}

void build(LI i, LI s, LI e)
{
	if(s==e)
		tree[i] = path[s];
	else
	{
		LI m = (s+e)/2;
		build(2*i,s,m);
		build(2*i+1,m+1,e);
		
		if(height[tree[2*i]] < height[tree[2*i+1]])
			tree[i] = tree[2*i];
		else
			tree[i] = tree[2*i+1];	
	} 
}

LI query(LI i, LI s, LI e, LI l, LI r)
{
	if(s>r || e<l) return -1;
	if(s==l && e==r) return tree[i];
	
	LI m = (s+e)/2;
	if(r<=m) 
		return query(2*i, s, m, l, r);
	else if(l>m)
		return query(2*i+1, m+1, e, l, r);
	else
	{
		LI lv = query(2*i, s, m, l, m);
		LI rv = query(2*i+1, m+1, e, m+1,r);
		if(height[lv] < height[rv])
			return lv;
		else
			return rv;
	}
}

void build2(LI i, LI s, LI e,VEC(LI) &arr)
{
	if(s==e)
	{
		tree2[i].f = factors[arr[path2[s]]];
		tree2[i].s.insert(path2[s]);
		return;
	}
	
	LI m = (s+e)/2;
	build2(2*i, s, m, arr);
	build2(2*i+1, m+1, e, arr);
	
	tree2[i].f = tree2[2*i].f;
	for(auto &x: tree2[2*i+1].f)
		tree2[i].f[x.first] += x.second;
	
	tree2[i].s = tree2[2*i].s;
	for(auto &x: tree2[2*i+1].s)
	{
		if(tree2[i].s.find(x)!=tree2[i].s.end())
		{
			for(auto &t: factors[arr[x]])
				tree2[i].f[t.first] -= t.second;
		}
		else
			tree2[i].s.insert(x);
	}
}

unordered_map<LI,LI> query2(LI i, LI s, LI e, LI l, LI r)
{
	if(s>r || e<l) return unordered_map<LI,LI>();
	if(s==l && e==r)
		return tree2[i].f;
	
	LI m = (s+e)/2;
	if(r<=m)
		return query2(2*i, s, m, l, r);
	else if(l>m)
		return query2(2*i+1,m+1,e,l,r);
	else
	{
		unordered_map<LI,LI> f1 = query2(2*i, s, m, l, m);
		unordered_map<LI,LI> f2 = query2(2*i+1, m+1, e, m+1, r);
		
		for(auto &x: f2)
			f1[x.first] += x.second;
		return f1;
	}
}
void process(VEC(LI)* graph, VEC(LI) &arr)
{
	memset(vis,0,sizeof vis);
	memset(entry,0,sizeof entry);
	memset(parent,-1,sizeof entry);
	memset(height,0,sizeof height);
	path.clear();
	path2.clear();
	
	dfs(graph,1,1);
	build(1,0,path.size()-1);
	
	build2(1,0,path2.size()-1,arr);
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
			graph[u].emplace_back(v);
			graph[v].emplace_back(u);
		}
		
		VEC(LI) arr(N+1);
		for(LI i=1; i<=N; i++) cin >> arr[i];
		
		process(graph,arr);
		
		LI Q;
		cin >> Q;
		while(Q--)
		{
			cin >> u >> v;
			if(entry[u]>entry[v])
			{
				LI temp = u;
				u = v;
				v = temp;
			}
			LI l,r;
			l = entry[u];
			r = entry[v];
			LI lca = query(1,0,path.size()-1,l,r);
			
			unordered_map<LI,LI> f;
			if(lca==u)
				f = query2(1,0,path2.size()-1,l,r);
			else
			{
				f = query2(1,0,path2.size()-1,leave[u],entry[v]);
				for(auto &x: factors[arr[lca]])	
					f[x.first] += x.second;
			}
			
			LI ans = 1;
			for(auto &x: f)
				ans = (ans * (x.second+1))%MOD;
			
			cout << ans << "\n";
		}
	}

	return 0;
}


