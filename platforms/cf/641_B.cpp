#include<bits/stdc++.h>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n+1];
		for(int i=1; i<=n; i++)
			cin >> a[i];
		
		int dp[n+1]={0};
		fill(dp,dp+n+1,1);
		for(int i=1; i<=n; i++) 
		{
			for(int j=2*i; j<=n; j+=i)
				if(a[j]>a[i])
					dp[j] = max(dp[j],dp[i]+1);
		}
		cout << *max_element(dp,dp+n+1) <<"\n";
	}

	return 0;
}


