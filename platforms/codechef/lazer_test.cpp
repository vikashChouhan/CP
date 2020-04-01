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


struct node {
	VEC(LI) arr;
};
LI Y;
void build(node *tree, LI i, LI s, LI e, LI *miny)
{
	if(s==e)
		tree[i].arr.emplace_back(miny[s]);
	else
	{
		LI m = (s+e)/2;
		build(tree, 2*i, s, m, miny);
		build(tree, 2*i+1, m+1, e, miny);
		
		merge(tree[2*i].arr.begin(),tree[2*i].arr.end(),tree[2*i+1].arr.begin(),tree[2*i+1].arr.end(),back_inserter(tree[i].arr));
	}
}

LI query(node *tree, LI i, LI s, LI e, LI l, LI r)
{
	if(s>r || l>e) return 0;
	
	if(l==s && r==e)
		return lower_bound(tree[i].arr.begin(),tree[i].arr.end(),Y)-tree[i].arr.begin();
	
	LI m = (s+e)/2;
	if(r<=m) return query(tree,2*i,s,m,l,r);
	if(l>m) return query(tree,2*i+1,m+1,e,l,r);
	return query(tree,2*i,s,m,l,m) + query(tree,2*i+1,m+1,e,m+1,r);
	
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
		
		LI arr[N];
		for(LI i=0; i<N; i++) cin >> arr[i];
		LI miny[N-1],maxy[N-1], i1=0;
		for(LI i=0; i<N-1; i++)
		{
			miny[i1] = -min(arr[i],arr[i+1]);
			maxy[i1++] = max(arr[i],arr[i+1]); 
		}
		
		node tree1[4*N],tree2[4*N];
		build(tree1,1,0,i1-1,miny);
		build(tree2,1,0,i1-1,maxy);
		
		
		LI x1,x2;
		while(Q--)
		{
			cin >> x1 >> x2 >> Y;
			LI cnt2 = query(tree2,1,0,i1-1,x1-1,x2-2);
			
			Y = -Y;
			LI cnt1 = query(tree1,1,0,i1-1,x1-1,x2-2);
			cout << x2 - x1 - cnt1-cnt2 << "\n";
			
		}
		
	}


	return 0;
}


