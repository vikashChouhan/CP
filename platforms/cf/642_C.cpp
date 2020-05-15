#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL count(LL i, LL j, LL m)
{
	if(i==m || j==m) return abs(m-j);	
	if(abs(m-j)==abs(m-i)) return abs(m-i);
	
	return max(abs(m-j),abs(m-i));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		LL n;
		cin >> n;
		n = n/2;
		LL ans = 0;
		ans = (n*(n+1)*(2*n+1))/6;
		cout << ans*8 <<"\n";
	}

	return 0;
}


