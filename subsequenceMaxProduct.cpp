#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	
	int cnt0,cntneg,maxneg;
	cnt0=cntneg=0;maxneg=INT_MIN;
	
	int prod=1;
	for(int i=0;i<size;i++)
	{
		if(a[i]==0) cnt0++;
		if(a[i]<0){
			cntneg++;
			maxneg = max(maxneg,a[i]);
		}
		if(a[i]!=0)
			prod*=a[i];
	}
	
	if(cnt0==size)
		prod=0;
	else if(cntneg==1)
	{
		if(cntneg==size){
		}
		else if((size-cntneg-cnt0)<=0)
			prod=0;
		else
			prod/=maxneg;
	}
	else if(maxneg!=INT_MAX && cntneg&1)
		prod/=maxneg;
	
	cout<<prod;
}
