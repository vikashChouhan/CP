#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)	
	cin>>a[i];
	
	int idx1=0,idx2=0;
	while(idx2<size)
	{
		if(a[idx2]!=0)
		{
			int t =a[idx2];
			a[idx2]=a[idx1];
			a[idx1]=t;
			
			idx1++;
			idx2++;
		}
		else
			idx2++;
	}
	
	cout<<"\n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
}

