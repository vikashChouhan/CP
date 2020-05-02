#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL unsigned long long
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
		int n;
		cin >> n;
		
		LL sum1 = 0,sum2=0;
		for(LL i=1; i<=n/2-1; i++)
			sum1+= (1<<i);
		sum1+=(1<<n);
		for(LL i=n/2; i<n; i++)
			sum2+=(1<<i);
			
		cout << (sum2>sum1?sum2-sum1:sum1-sum2)<<"\n";
	}

	return 0;
}


