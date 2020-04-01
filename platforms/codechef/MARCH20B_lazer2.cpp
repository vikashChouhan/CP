#include<bits/stdc++.h>
using namespace std;

#define FAST_EXECUTION

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007
#define INF 1000000000000000000ll

#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:247474112")
#endif

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


LI Y;
struct node {
	VEC(LI) lowy, highy;
};



void build(node *tree, LI i, LI s, LI e, VEC(PAIR(LI,LI)) &arr)
{
	if(s==e)
	{
		tree[i].lowy.emplace_back(-arr[s].first);
		tree[i].highy.emplace_back(arr[s].second);
	}
	else
	{
		LI mid = (s+e)/2;
		build(tree,2*i,s,mid,arr);
		build(tree,2*i+1,mid+1,e,arr);
		
		merge(tree[2*i].lowy.begin(),tree[2*i].lowy.end(),tree[2*i+1].lowy.begin(),tree[2*i+1].lowy.end(),back_inserter(tree[i].lowy));
		merge(tree[2*i].highy.begin(),tree[2*i].highy.end(),tree[2*i+1].highy.begin(),tree[2*i+1].highy.end(),back_inserter(tree[i].highy));

	}
}

LI query(node *tree, LI i, LI s, LI e,LI l,LI r)
{
	if(s>r || e<l) return 0;
	
	if(s==l && e==r)
	{
		LI idx1 = lower_bound(tree[i].highy.begin(),tree[i].highy.end(),Y)-tree[i].highy.begin();
		Y = -Y;
		LI idx2 = lower_bound(tree[i].lowy.begin(),tree[i].lowy.end(),Y)-tree[i].lowy.begin();
		Y = -Y;
		return r-l+1-idx1-idx2;
	}
	
	LI m = (s+e)/2;
	if(r<=m) return query(tree,2*i,s,m,l,r);
	else if(l>m) return query(tree,2*i+1,m+1,e,l,r);
	else
		return query(tree, 2*i, s, m, l, m) + query(tree, 2*i+1, m+1, e, m+1,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int t;
	cin >> t;
	while(t--)
	{
		LI N, Q;
		cin >> N >> Q;
		
		LI x,prev;
		VEC(PAIR(LI,LI)) seg;
		seg.reserve(N-1);
		for(LI i=1; i<=N; i++)
		{
		    cin >> x;
		    if(i!=1)
		        seg.emplace_back(make_pair(min(x,prev),max(x,prev)));
		    prev = x;
		}
		
		node tree[4*N];
		build(tree,1,0,seg.size()-1,seg);
		
		LI x1,x2;
		while(Q--)
		{
			cin >> x1 >> x2 >> Y;
			cout << query(tree,1,0,seg.size()-1,x1-1,x2-2) << "\n";
		}
	}

	return 0;
}


