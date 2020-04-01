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

VEC(LI) path;
VEC(LI) weight;
VEC(LI) firstoccr;
struct node {
	LI min = INT_MAX;
	LI max = INT_MIN;
};
void dfs(VEC(PAIR(LI,LI)) *graph, LI u, int *vis)
{
	vis[u] = 1;
	path.push_back(u);
	firstoccr[u] = path.size()-1;
	for(auto x: graph[u])
	{
		if(!vis[x.first])
		{
			weight.push_back(x.second);
			dfs(graph,x.first,vis);
			path.push_back(u);
			weight.push_back(x.second);
		}
	}
}

void build(node *tree, LI i, LI s, LI e)
{
	if(s==e)
		tree[i].min = tree[i].max = weight[s];
	else
	{
		LI m = (s+e)/2;
		build(tree,2*i+1,s,m);
		build(tree,2*i+2,m+1,e);
		tree[i].min = min(tree[2*i+1].min,tree[2*i+2].min);
		tree[i].max = max(tree[2*i+2].max,tree[2*i+2].max); 
	}
}

node query(node *tree,LI i, LI s, LI e, LI l, LI r)
{
	if(s>r || e<l) return node();
	
	if(s==l || e==r)
		return tree[i];
	
	LI mid = (s+e)/2;
	if(r<=mid)
		return query(tree,2*i+1,s,mid,l,r);
	else if(l>mid)
		return query(tree,2*i+2,mid+1,e,l,r);
	else
	{
		node n1 = query(tree,2*i+1,s,mid,l,mid);
		node n2 = query(tree,2*i+2,mid+1,e,mid+1,r);
		
		node n3;
		n3.max = max(n1.max,n2.max);
		n3.min = min(n1.min,n2.min);
		return n3;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI N;
	cin >> N;
	
	VEC(PAIR(LI,LI)) graph[N+1];
	LI u,v,w;
	for(LI i=0; i<N-1; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	
	int vis[N+1] = {0};
	firstoccr.resize(N+1);
	dfs(graph, u, vis);

	node tree[4*N];
	build(tree,0,0,N-1);
	
	LI q;
	cin >> q;
	cout << path;
	cout << weight;
	while(q--)
	{
		cin >> u >> v;
		LI f = min(firstoccr[u],firstoccr[v]);
		LI l = max(firstoccr[u],firstoccr[v])-1;
		cout << "f="<< f<< "l="<<l<<"\n";
		node ans = query(tree,0,0,N-1,f,l);
		cout << ans.min << " " << ans.max << "\n";
	}
	return 0;
}


