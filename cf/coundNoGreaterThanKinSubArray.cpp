#include<bits/stdc++.h>
using namespace std;

#define li long int

li search(li *a,li start,li end,li val)
{
	
	while(start<=end)
	{
		li mid = (start+end)/2;
		if(val<=a[mid])	
			end=mid-1;
		else
			start=mid+1;
	}
	return end;
}
int main()
{
	li n;
	cin>>n;
	li a[n+1];
	for(li i=1;i<=n;i++)cin>>a[i];	
	
	cout<<search(a,1,n,4);
}
