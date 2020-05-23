#include<bits/stdc++.h>
using namespace std;

#define LI long int

template <typename T>
T GCD(T a, T b)
{T temp;while(b>0){temp = b;b = a%b;a = temp;}
return a;}

long long lcm(long long  a, long long b)
{
	return (a*1ll*b)/__gcd(a,b)*1ll;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n;
		cin >> n;
		long long ans = 0,x;
		long long gcd=0,l=-1;
		cin >> l;
		cin >> x;
		ans = lcm(l,x);
		for(long i=2; i<n; i++)
		{
			cin >> x;
			ans = __gcd(ans,lcm(l,x));
			l = __gcd(l,x);
		}
		
	
		cout << ans;


	return 0;
}


