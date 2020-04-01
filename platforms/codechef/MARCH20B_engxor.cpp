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
		LI even=0, odd=0;
		LI x;
		for(LI i=0; i<N; i++)
		{
			cin >> x;
			if(__builtin_parity(x)&1) odd++;
			else even++;
		}
		
		
		while(Q--)
		{
			cin >> x;
			if(__builtin_parity(x)&1)
				cout << odd << " " << even << "\n";
			else
				cout << even << " " << odd << "\n";
		}
	}

	return 0;
}


