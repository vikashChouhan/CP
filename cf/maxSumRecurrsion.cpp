#include<iostream>
using namespace std;
#define li long int

li maxSum(li n)
{
    if(n/2==0)
        return n;
    else
    {
        li n1 = n/2;
        li n2 = n/3;
        li n3 = n/4;
        
        li a1 = maxSum(n1);
        li a2 = maxSum(n2);
        li a3 = maxSum(n3);
        
        li ans1=n1+n2+n3;
        ans1 = max(ans1,a1+n2+n3);
        ans1 = max(ans1,n1+a2+n3);
        ans1 = max(ans1,n1+n2+a3);
        ans1 = max(ans1,a1+a2+n3);
        ans1 = max(ans1,a1+n2+a3);
        ans1 = max(ans1,n1+a2+a3);
        ans1 = max(ans1,a1+a2+a3);
        return max(ans1,n);
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    li n;
	    cin>>n;
	    cout<<maxSum(n)<<"\n";
	}
	return 0;
}
