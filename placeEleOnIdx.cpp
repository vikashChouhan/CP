#include<iostream>
using namespace std;
/*
int main()
{
	int size;
	cin>>size;
	int a[size];
	int t[size];
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
		t[i]=-1;
	}
	
	
	for(int i=0;i<size;i++)
		if(a[i]!=-1)
			t[a[i]]=a[i];
	
	cout<<"\n";
	for(int i=0;i<size;i++)
		cout<<t[i]<<" ";
}

*/
int main()
{
	int size;
	cin>>size;
	int a[size];
	int t[size]={0};
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<size;i++)
		if(a[i]!=-1)
			t[a[i]]=1;
	
	for(int i=0;i<size;i++)
		if(t[i]!=0)
			a[i]=i;
		else
			a[i]=-1;
	
	cout<<"\n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
}
