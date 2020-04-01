#include<bits/stdc++.h>
using namespace std;

void multiply(int M1[2][2],int M2[2][2])
{
	int M[2][2];
	M[0][0] = M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0];
	M[0][1] = M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1];
	M[1][0] = M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0];
	M[1][1] = M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1];
	
	M2[0][0]=M[0][0];
	M2[0][1]=M[0][1];
	M2[1][0]=M[1][0];
	M2[1][1]=M[1][1];
}
void power(int M[2][2],int n)
{
	if(n==1)
		return;

	int temp[2][2] = {{1,1},{1,0}};
	
	multiply(M,M);
	power(M,n/2);
	
	
	if(n&1)
		multiply(temp,M);
}
int fibo(int n)
{
	int M[2][2] = {{1,1},{1,0}};
	if(n==0)	
		return 0;
	power(M,n-1);
	
	return M[0][0];
	
}
int main()
{
	cout<<fibo(9);
}
