#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--) {
		ull x,y,l,r;
		cin>>x>>y>>l>>r;
		
		if(x==0 || y==0 || r==0)
		{
			cout<<l<<"\n";
			continue;
		}
		else
		{
			ull Or = x|y;
			ull ans=0;
			if(Or>=l && Or<=r)
				ans = Or;
			else
			{
				int mb = log10(Or)/log10(2);
				int lb=0;
				if(l!=0)
					lb = log10(l)/log10(2);
				//cout << lb << " " << mb<<endl;
				if(lb>mb)
					for(int i=lb; i>mb; i--)
						ans|= (1<<i);
				for(int i=mb; i>=0; i--)
				{
					int b = (Or>>i)&1;
					int lb = (l>>i)&1;
					
					if(b==1)
					{
						ull div = l/(1<<i);
						ull rem = l%(1<<i);
						if(div%2==0 && l+(1<<i)-rem <= r)
							ans |= 1<<i;
						else if(div&1)
							ans |= 1<<i;
						
						if(ans>r || (ans==r && (((x>>i)&1)==0 || ((y>>i)&1)==0)))
						{
							ans &= ~(1<<i);	
						}
					}
				}
				
				while(ans<l)
				{
					for(int i=mb; i>=0; i--)
					{
						int ansb = (ans>>i)&1;
						int lb = (l>>i)&1;
						
						if(ansb==0)
						{
							ull div = l/(1<<i);
							ull rem = l%(1<<i);
							if(div%2==0 && l+(1<<i)-rem <= r)
								ans |= 1<<i;
							else if(div&1)
								ans |= 1<<i;
							
							if(ans>r)
							{
								ans &= ~(1<<i);	
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}


	return 0;
}


