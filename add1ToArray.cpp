#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size;
	cin>>size;
	vector<int>a;
	for(int i=0;i<size;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	
	int carry=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int sum = 0;
		if(i==a.size()-1)
			sum = a[i]+carry+1;
		else
			sum = a[i]+carry;
		
		a[i] = sum%10;
		carry = (sum-a[i])/10;
		
		if(carry==0)
			break;
	}
	if(carry!=0)
		a.insert(a.begin(),carry);
	
	for(auto x:a)
		cout<<x<<" ";
}
