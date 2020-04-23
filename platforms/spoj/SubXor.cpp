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

struct Trie {
	Trie *left = NULL, *right=NULL;
	int lcnt=0, rcnt=0;
}*root=NULL;

void insert(int x)
{
	
	Trie *p = root;
	for(int i=20; i>=0; i--)
	{
		int b = (x>>i) &1;
		if(b)
		{
			p->rcnt++;
			if(p->right==NULL)
				p->right = new Trie();
			p = p->right;
		}
		else
		{
			p->lcnt++;
			if(p->left==NULL)
				p->left = new Trie();
			p = p->left;
		}
	}
	
}

LI query(int x, int k)
{
	if(root==NULL) return 0;
	
	Trie *p = root;
	LI ans = 0;
	for(int i=20; i>=0; i--)
	{
		int kb = (k>>i) & 1;
		int xb = (x>>i) & 1;
		if(kb)
		{
			if(xb)
			{
				ans += p->rcnt;
				if(p->left==NULL)
					return ans;
				p = p->left;
			}
			else
			{
				ans += p->lcnt;
				if(p->right == NULL)
					return ans;
				p  = p->right;
			}
		}
		else
		{
			if(!xb)
			{
				if(p->left==NULL)
					return ans;
				p = p->left;
			}
			else
			{
				if(p->right==NULL)
					return ans;
				p = p->right;
			}
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int temp=0, x;
		LI ans = 0;
		root = new Trie();
		insert(0);
		for(int i=0; i<n; i++)
		{
			cin >> x;
			temp = temp ^ x;
			ans += query(temp, k);
			insert(temp);
		}
		cout << ans << "\n";
	}

	return 0;
}


