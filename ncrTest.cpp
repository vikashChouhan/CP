#include<iostream>
using namespace std;

#define MOD 1000000007
long int a[10001][10001]={0};

long int ncr(long int n,long int r)
{
	if(a[n][r]!=0)
		return a[n][r];

	else if(n==r || r==0)
		return 1;
	else	
	{
		a[n][r] = (ncr(n-1,r-1)%MOD + ncr(n-1,r)%MOD)%MOD;
		return a[n][r];
	}
}
int main()
{
	long int ans=0;
	for(long int i=0;i<=10;i++)
		ans= (ans + ncr(10,i))%MOD;
	cout<<ans;
}
