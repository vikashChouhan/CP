#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007

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
		int n,d;
		cin >> n >> d;
		
		int ans = 0;
		int a[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
			
		ans = a[0];
		int i=1;
		
		int ini=a[0];
		while(1)
		{
			ini = a[0];
			i=1;
		while(d>0 && i<n)
		{
			if(a[i]==0)
			{
				i++;
				continue;
			}
			if(d >= a[i]*i)
			{
				
				ans += a[i];
				d -= i*a[i];
				a[i] -= a[i];
				
			}
			else
			{
				ans += (d/i);
				a[i] -= (d/i);
				d -= (d/i)*i;
			}
			i++;
		}
			if(ini==a[0])
				break;
			
		}
		
		cout << ans << "\n";
	}

	return 0;
}


