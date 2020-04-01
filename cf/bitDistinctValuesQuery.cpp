#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define li long int
int main()
{
	/*
	li n;
	cin>>n;
	li a[n+1];
	for(li i=1;i<=n;i++)
		cin>>a[i];
	
	bitset<MAX>bit[n+1];
	build(bit,a,n);
	
	cin>>q;
	while(q--)
	{
		li l,r;
		cin>>l>>r;
		bitset<MAX>ub = query(bit,n,r);
		bitset<MAX>lb;
		if(l!=1)
		{
			lb = query(bit,n,l-1);
			bitset<MAX>temp = ub&lb;
			temp = temp&ub;
		
		
	}
	*/
	set<int>s1,s2;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	
	s2.insert(3);
	s2.insert(4);
	s2.insert(5);
	
	vector<int>s3;
	set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),s3.begin());
	for(auto x:s3)
		cout<<x<<" ";
}
