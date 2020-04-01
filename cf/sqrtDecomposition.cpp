#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	int len = int(sqrt(n*1.0)) +1;
	int b[len]={0};
	for(int i=0;i<n;i++)
		b[i/len]+=a[i];
	
	for(int i=0;i<n;i++)
	{
		cout<<i/len<<" "<<b[i/len]<<"\n";
	}
	int q;
	cin>>q;
	while(q--)	
	{
		int l,r;
		cin>>l>>r;
		int ans = 0;
		/*for(int i=l;i<=r;)
		{
			if(i%len==0 && i+len-1<=r)
			{
				ans += b[i/len];
				i+=len;
			}
			else
			{
				ans+=a[i];
				i++;
			}
		}*/
		
		int c_l = l/len, c_r = r/len;
		if(c_l==c_r)
			for(int i=l;i<=r;i++)
				ans+=a[i];
		else
		{
			for(int i=l;i<(c_l+1)*len;i++)
				ans+=a[i];
			for(int i=c_l+1;i<=c_r-1;i++)
				ans+=b[i];
			for(int i=c_r*len;i<=r;i++)
				ans+=a[i];
		}
		cout<<ans<<"\n";
	}
}

