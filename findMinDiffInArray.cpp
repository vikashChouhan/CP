#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	//by sorting
	/*
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	
	sort(a,a+size);
	int diff=INT_MAX;
	for(int i=0;i<size-1;i++)	
		diff = min(diff,a[i+1]-a[i]);
	cout<<diff;
	*/
	
	
	int size;
	cin>>size;
	int maxele=INT_MIN;
	int a[size];
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
		maxele = max(maxele,a[i]);
	}
	
	int occ[maxele+1]={0};
	for(int i=0;i<size;i++)	
	{
			occ[a[i]]=1;
	}
	int previdx=-1;
	int ans=INT_MAX;
	for(int i=1;i<=maxele;i++)
	{
		if(occ[i]==1 && previdx!=-1)
		{
			ans = min(ans,i-previdx);
			previdx = i;
		}
		else if(occ[i]==1);
			previdx=i;
	}
	cout<<ans;
		
}
