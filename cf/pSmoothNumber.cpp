#include<bits/stdc++.h>
using namespace std;

/*
//brute force
int mpf(int n)
{
	int maxpf;
	while(n%2==0)
	{
		maxpf = 2;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			maxpf = i;
			n/=i;
		}
	}
	if(n>2)
		maxpf = max(maxpf,n);
	
	return maxpf;
}
int main()
{
	int cnt=0;
	int n=10;
	int p=10;
	while(cnt!=20)
	{
		if(mpf(n)>=p)
		{
			cout<<n<<" ";
			cnt++;
		}
		n++;
	}
}
*/

void getprimes(int *arr,int p)
{
	int arr[p+1]={0};
	arr[2]=1;
	for(int i=2;i*i<=p;i++)
		if(arr[i])
			for(int j=i*i;j<=p;j+=i)
				arr[i]=0;
	
	
}
void getsmooth(int n,int p)
{
	vector<int>primes;
	getprimes(primes,n,p);
}
int main()
{
	int n,p;
	cin>>n>>p;
	getsmooth(n,p);
}
