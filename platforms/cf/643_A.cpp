#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

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
		ull a,k;
		cin >> a >> k;
		k--;
		while(k--)
		{
			int m=10,M=0;
			ull temp = a;
			while(temp>0)
			{
				m = m>temp%10?temp%10:m;
				M = M<temp%10?temp%10:M;
				temp/=10;
			}
			
			if(m*M==0) break;
			a += m*M;
		}
		cout << a << "\n";
	}

	return 0;
}


