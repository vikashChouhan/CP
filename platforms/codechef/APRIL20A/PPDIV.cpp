#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define ULL unsigned long long
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

VEC(LI) primes;

void sieve()
{
	int p[70];
	fill(p,p+70,1);
	p[2] = 1;
	for(int i=2; i<=70; i++)
	{
		if(p[i])
		{
			primes.emplace_back(i);
			for(int j=i*i; j<=70; j+=i)
				p[j] = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	sieve();
	cout << primes;


	return 0;
}


