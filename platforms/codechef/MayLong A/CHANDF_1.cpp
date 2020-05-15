#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;


ull solve(ull x, ull y, ull l, ull r)
{
	if(x==0 || y==0 || r==0) return l;
	
	ull Or = x|y;
	ull ans=0;
	if(Or>=l && Or<=r) ans = Or;
	else
	{
		ull mlb = l==0?0:log2(l);
		ull mrb = log2(r);
		vector<pair<ull,ull>> divisions;
		for(ull i=mlb; i<=mrb; i++)
			divisions.push_back({i,1<<i});
		
		for(int i=0; i<divisions.size(); i++)
		{
			ull msb = divisions[i].first;
			ull tempans = 1<<msb;
			
			if((x&y)==0)
			{
				ull xmsb = (x>>msb)&1;
				ull ymsb = (y>>msb)&1;
				int j;
				if(xmsb && !ymsb)
				{
					for(j=msb-1; j>=0; j--)
						if((y>>j)&1 && (tempans|(1<<j))<=r)
						{
							tempans|=(1<<j);
							break;
						}
				}
				else if(!xmsb && ymsb)
				{
					for(j=msb-1; j>=0; j--)
						if((x>>j)&1 && (tempans|(1<<j))<=r)
						{
							tempans|=(1<<j);
							break;
						}
				}
				else if(!xmsb && !ymsb)
				{
					for(j=msb-1; j>=0; j--)
					{
						ull xb = (x>>j)&1;
						if(xb)
						{
							int t;
							for(t=j; t>=0; t--)
							{
								ull yb = (y>>t)&1;
								if(yb && (tempans|(1<<j)|(1<<t))<=r)
								{
									tempans |= (1<<j)|(1<<t);
									break;
								}
							}
							
							if(t>=0) break;
						}
					}
				}
				
				if(j<0)
				{
					divisions[i].second = max(1ull<<msb,l);
					continue;
				}
			}
			
			for(int j=msb-1; j>=0; j--)
			{
				ull ob = (Or>>j)&1;
				if(ob && (tempans|(1<<j))<=r)
					tempans|=(1<<j);
			}
			if(tempans<l)
				tempans |= l;
			divisions[i].second = tempans;
		}
		
		ull maxF = 0;
		ans=l;
		for(pair<int,ull> var: divisions)
		{
			if((x&var.second)*(y&var.second)>maxF && 
			var.second>=l && var.second<=r)
			{
				ans = var.second;
				maxF = (x&var.second)*(y&var.second);
			}
		}
		ull And = x&y;
		if(maxF < And && And>=l && And<=r)
			ans = And;
	}
	
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--) {
		ull x,y,l,r;
		cin>>x>>y>>l>>r;
		
		cout << solve(x,y,l,r) <<"\n";
		
	}


	return 0;
}


