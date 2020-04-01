#include<bits/stdc++.h>
using namespace std;

long power(int x,int n)
{
	if(n==0) return 1;
	if(n&1)
		return x*power(x*x,(n-1)/2);
	return power(x*x,n/2);
}


//prime factors
void primeFactors(int n)
{
	while(n%2==0)
	{
		cout<<2<<" ";
		n/=2;
	}
	for(int i=3;i*i<=n;i++)
	{
		while(n%i==0)
		{
			cout<<i<<" ";
			n/=i;
		}
	}
	if(n>2)
		cout<<n<<" ";
}
int main()
{
	//cout<<power(5,4);
	primeFactors(12);
}
