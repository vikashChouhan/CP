#include<bits/stdc++.h>
using namespace std;

bool safe(int *a,int r,int c,int R,int C)
{

	
	for(int i=0;i<c;i++)
		if(*(a+(r*C)+i))
			return false;	
			
	for(int i=r,j=c;i>=0&&j>=0;i--,j--)
		if(*(a+(i*C)+j))
			return false;
	
	
	for(int i=r,j=c;i<R&&j>=0;i++,j--)
		if(*(a+(i*C)+j))
			return false;
	
	return true;
	
}
bool placeQ(int *a,int c,int count,int R,int C,int n)
{
	
	if(count==n)
		return true;
	
	for(int i=0;i<R;i++)
	{
		if(safe(a,i,c,R,C))
		{
			*(a+(C*i)+c) = 1;
			
			if(placeQ(a,c+1,count+1,R,C,n))
				return true;
			
			*(a+(i*C)+c)=0;
		}
	}
	return false;
}
int main()
{
	int r,c,n;
	cin>>r>>c>>n;
	int a[r][c]={0};
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			a[i][j]=0;
	}
	placeQ(a[0],0,0,r,c,n);
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
