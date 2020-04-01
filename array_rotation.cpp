#include<iostream>
using namespace std;
/*
int main()
{
	int size = 4;
	int a[size]={1,2,1,1};
	
	int idx=-1;
	for(int i=0;i<size-1;i++)
		if(a[i]>a[i+1])
		{
			idx = i+1;
			break;
		}
	if(idx==-1)
		cout<<"no rotation";
	else
	cout<<(size-idx)%size;
}*/

int main()
{
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	
	int k;cin>>k;
	k= k%size;
	
	int temp[k];
	for(int i=0;i<k;i++)
		temp[i]=a[i];
	
	for(int i=0;i<size-k;i++)
		a[i]=a[i+k];
	for(int i=size-k;i<size;i++)
		a[i]=temp[i-(size-k)];
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
}
