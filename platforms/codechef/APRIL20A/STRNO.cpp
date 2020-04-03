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


LI factors(LI N)
{
	LI cnt=0;
	while(N%2==0)
	{
		cnt++;
		N/=2;
	}
	for(LI i=3; i*i<=N; i+=2)
	{
		while(N%i==0)
		{
			cnt++;
			N/=i;
		}
	}
	if(N>2) cnt++;
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI t;
	cin >> t;
	while(t--)
	{
		LI X, K;
		cin >> X >> K;
		if((X==1 && K==1) || K<=factors(X)) cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}


