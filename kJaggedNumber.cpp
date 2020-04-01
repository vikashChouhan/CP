#include<bits/stdc++.h>
using namespace std;

/*
// K-jagged number
// smallest prime factor of n is >= k
//brute force
int mpf(int n)
{
	int maxpf;
	while(n%2==0)
	{
		maxpf = 2;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			maxpf = i;
			n/=i;
		}
	}
	if(n>2)
		maxpf = max(maxpf,n);
	
	return maxpf;
}
int main()
{
	int cnt=0;
	int n=10;
	int p=10;
	while(cnt!=20)
	{
		if(mpf(n)>=p)
		{
			cout<<n<<" ";
			cnt++;
		}
		n++;
	}
}
*/

void getprimes(int *arr,int p)
{
	
	for(int i=2;i*i<=p;i++)
		if(arr[i])
			for(int j=i*i;j<=p;j+=i)
					arr[j]=0;
	
	
}
void getKjagged(int L,int R,int k)
{
	int arr[R+1];
	for(int i=0;i<=R;i++)arr[i]=1;
	arr[0]=arr[1]=0;
	getprimes(arr,R);
	for(int i=2;i<=R;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	for(int i=2;i<R+1;i++)
	{
		if((arr[i]==1 && i>=k) || (arr[i]>1 && i/arr[i]>=k))
		{
			if(arr[i]>1 && (i/arr[i])*(arr[i]+1)<=R)
				arr[(i/arr[i])*(arr[i]+1)]=arr[i]+1;
			else if(arr[i]==1 && 2*i<=R)
				arr[2*i] = 2;
		}
		else
			arr[i]=0;
	}
	
	for(int i=L;i<=R;i++)
	{
		if(arr[i]!=0)
			cout<<i<<" ";
	}
}
int main()
{
	int l,r,k;
	cin>>l>>r>>k;
	getKjagged(l,r,k);
}
