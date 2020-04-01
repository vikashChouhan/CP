#include<bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long int k;
		cin>>n>>k;
		long int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		for(int i=0;i<n;i++)
		{
			if(a[i]>k && i+1<=n-1)
			{
				long int temp = a[i]-k;
				a[i] =k;
				a[i+1]-=temp;
			}
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<"\n";
		}
		
		long int sum=0;
		for(int i=0;i<n;i++)	
			sum+=a[i];
		cout<<sum<<"\n";
	}
}
