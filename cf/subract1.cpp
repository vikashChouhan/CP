#include<bits/stdc++.h>
using namespace std;

#define li long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	li n,k;
	cin>>n>>k;
	
	for(int i=0;i<k;i++)
	{
		li t = n%10;
		if(t!=0)
			n=n-1;
		else
			n/=10;
	}
	cout<<n<<"\n";
}
