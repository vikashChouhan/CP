#include<bits/stdc++.h>
using namespace std;

#define li long int

li gcd,x,y;

void extendedEuclid(li a,li b)
{
	if(b==0)
	{
		gcd = a;
		x = 1;
		y = 0;
	}
	else
	{
		extendedEuclid(b,a%b);
		li temp = x;
		x = y;
		y = temp - y*(a/b);
	}
}

int main()
{
	extendedEuclid(6,4);
	cout<<gcd<<" x="<<x<<" y="<<y;
}
