#include<bits/stdc++.h>
using namespace std;

void sieveSimple(vector<int>&primes,int n)
{
	int p[n+1];
	memset(p,1,sizeof(p));
	
	p[2]=1;
	for(int i=2;i*i<=n;i++)
		if(p[i])
			for(int j=i*i;j<=n;j+=i)
				p[j]=0;
	
	for(int i=2;i<=n;i++)	
		if(p[i])
			primes.push_back(i);
}
int main()
{
	/*
	int a[101];
	fill(a,a+101,1);
	a[2]=1;
	for(int i=2;i*i<=100;i++)
	{
		if(a[i])
			for(int j=i*i;j<=100;j+=i)
				a[j]=0;
	}
	
	for(int i=2;i<=100;i++)
		if(a[i])
			cout<<i<<" ";
	
	*/
	
	//segmented sieve
	int n=100;
	vector<int>p;
	sieveSimple(p,sqrt(n));
	
	for(auto x:p)
		cout<<x<<" ";
	cout<<"\n";
	int start = sqrt(n)+1;
	int end = start+sqrt(n);
	
	while(end<=n)
	{
		int segp[int(sqrt(n))+1];
		memset(segp,1,sizeof(segp));
		for(auto sp:p)
		{
			int fp = start%sp;
			fp = start+ sp-fp;
			
			for(int i=fp;i<=end;i+=sp)
				segp[i-start]=0;
				
		}
		
		
		for(int i=start;i<=end;i++)
			if(segp[i-start])
				cout<<i<<" ";
		cout<<"\n";
		start=end+1;
		end=start+sqrt(n);
		
	}
	
}
