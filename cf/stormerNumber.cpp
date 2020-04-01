#include<bits/stdc++.h>
using namespace std;

long int pf(long int n)
{
	long int maxpf=2;
	while(n%2==0)
	{
		maxpf=2;
		n/=2;
	}
	for(int i=3;i*i<=n;i++)
	{
		while(n%i==0)
		{
			maxpf=i;
			n/=i;
		}
	}
	if(n>2)
		maxpf = max(maxpf,n);
	return maxpf;
}

int main()
{
	long int n;
	cin>>n;
	if(pf(n*n+1)>=2*n)
		cout<<"is a stormer number";
	else
		cout<<"no not a stormer number";
}
