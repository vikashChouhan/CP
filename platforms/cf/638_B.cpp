#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007
#define INF 1000000000000000000ll

#define DEBUG(x) cerr << "{" << #x <<": " << x <<"}   ";
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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		set<int> ss;
		for(int i=0, x; i<n; i++) 
		{
			cin >> x;
			ss.insert(x);
		}
		
		if(k<ss.size()) 
		{
			cout << "-1\n";
			continue;
		}
		cout << k*n << "\n";
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<k-ss.size(); j++)
				cout << n << " ";
			for(int x: ss)
				cout << x << " ";
		}
		cout<<"\n";
	}

	return 0;
}


