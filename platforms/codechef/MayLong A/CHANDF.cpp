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
		
		ull ans=0, curr = x|y;
		for(int i=31; i>=0; i--) {
			
			int cb = (curr>>i)&1;
			int lb = (l>>i)&1;
			
			if(cb==1) {
				cout << i << " "<<"lb="<<lb<<"\n";
				if(lb==0) {
					ull diff = (1<<i) - l%(1<<i);
					
					if(l+diff<=r && (ans|(1<<i)) <= r)
						ans = ans|(1<<i);
				}
				else if(ans|(1<<i) <=r) {
					ans=ans|(1<<i);
				}
			}
		}
		cout << "ans=";
		cout << ans <<"\n";
	}


	return 0;
}


