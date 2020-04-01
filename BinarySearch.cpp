#include<bits/stdc++.h>
using namespace std;

int search(int *a,int start,int end,int val)
{
	int mid = (start+end)/2;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(val<a[mid])
			end=mid-1;
		else if(val>a[mid])
			start=mid+1;
		else
			return mid;
	}
	return -1;
}

int GreatestNumberLessThanN(int *a,int start,int end,int val)
{
	int ans=0;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(val<a[mid])
			end=mid-1;
		else if(val>a[mid])
		{
			ans=mid;
			start=mid+1;
		}
		else
			end=mid-1;
	}
	if(ans)
		return ans;
	else
		return -1;
}

int LowestNumberGreaterThanN(int *a,int start,int end,int val)
{
	int ans=0;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(val<a[mid])
		{
			ans=mid;
			end=mid-1;
		}
		else if(val>=a[mid])
			start=mid+1;
	}
	
	return ans>0?ans:-1;
}

int LastPosOfN(int *a,int start,int end,int val)
{
	int ans=0;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(val>a[mid])
			start=mid+1;
		else if(val<a[mid])
			end=mid-1;
		else
		{
			ans=mid;
			start=mid+1;
		}
	}
	return ans>0?ans:-1;
}

int FirstPosOfN(int *a,int start,int end,int val)
{
	int ans=0;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(val<a[mid])
			end=mid-1;
		else if(val>a[mid])
			start=mid+1;
		else
		{
			ans=mid;
			end=mid-1;
		}
			
	}
	return ans>0?ans:-1;
}
int main()
{
	int a[]={2,2,2,3,3,4,4,5,6,7,8,8};
	int size = sizeof(a)/sizeof(a[0]);
	
	//cout<<search(a,0,size-1,3);
	//cout<<GreatestNumberLessThanN(a,0,size-1,6);
	//cout<<LowestNumberGreaterThanN(a,0,size-1,4);
	//cout<<LastPosOfN(a,0,size-1,3);
	cout<<FirstPosOfN(a,0,size-1,8);
}
