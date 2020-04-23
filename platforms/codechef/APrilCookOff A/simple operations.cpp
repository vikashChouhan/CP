#include <bits/stdc++.h>
using namespace std;

#define li long int 
int main() {
    
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);cout.tie(NULL);
    
    li t;
    cin >> t;
    while(t--)
    {
        string s,r;
        cin >> s >> r;
        li k=0,l=0;
        int cnt=0;
        li gapcnt=0;
        bool cancnt=false;
        vector<int>gaps;
        for(li i=0; i<s.length(); i++)
        {
        	if(s[i]!=r[i])
        	{
        		if(cancnt && gapcnt!=0)
				{
					gaps.push_back(gapcnt);
					gapcnt=0;	
				}
        		l++;
        		if(cnt==0)
				{
					k++;
					cnt=1;
					cancnt=true;
				}
				
			}
			else
			{
				if(cancnt)
					gapcnt++;
				if(cnt==1) cnt=0;
			}
		}
		
		li ans = k*l;
		for(li i=0; i<gaps.size(); i++)
		{
			k--;
			l+=gaps[i];
			ans = min(ans,k*l);
		}
		cout << ans <<"\n";
    }
	return 0;
}

