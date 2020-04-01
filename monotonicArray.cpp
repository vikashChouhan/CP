#include<bits/stdc++.h>
using namespace std;

int main()
{
	//checking monotonic array (either incresing or decreasing)
	
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	int inc=1,dec=1;
	for(int i=0;i<size-1;i++)
		if(a[i]>a[i+1])
		{
			inc=0;
			break;
		}
	for(int i=0;i<size-1;i++)
		if(a[i]<a[i+1])
		{
			dec=0;
			break;
		}
	if(inc || dec)
		cout<<"monotonic";
	else
		cout<<"no";		
}
