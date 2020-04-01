#include<bits/stdc++.h>

using namespace std;

int solve(int *dp,int *a,int n){
	if(n==0)	
		return 0;
	if(dp[n]!=0)
		return dp[n];
	else{
		int ans = INT_MIN;
		for(int i=1;i<n;i++)
			ans = max(ans,solve(dp,a,n-i)+a[i]);
		
		dp[n]=ans;
		return ans;
	}
}


int main()
{
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int dp[n+1]={0};
		dp[1]=a[1];
		
		cout<<sove(dp,a,n)<<"\n";
	}
}

