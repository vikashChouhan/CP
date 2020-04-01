#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin>>n;
	unordered_set<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.insert(x);
	}
	int m;
	cin>>m;
	unordered_set<int>b;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		b.insert(x);
	}
	
	for(auto xa:a)
	{
		for(auto xb:b)
			if(a.find(xa+xb)==a.end() && b.find(xa+xb)==b.end())
			{
				cout<<xa<<" "<<xb;
				return 0;
			}
	}
}
