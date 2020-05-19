#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define pii pair<int,int>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		LI ans = 0;
		set<pair<pii,pii>>mm;
		int x=0,y=0,prevx=0,prevy=0;
		for(char ch: s)
		{
			if(ch=='N') y++;
			else if(ch=='S') y--;
			else if(ch=='W') x--;
			else if(ch=='E') x++;
			
			if(mm.find({{prevx,prevy},{x,y}})!=mm.end()
			|| mm.find({{x,y},{prevx,prevy}})!=mm.end())
			{
				ans+=1;
			}
			else
				ans+=5;
			mm.insert({{prevx,prevy},{x,y}});
			mm.insert({{x,y},{prevx,prevy}});
			prevx=x,
			prevy=y;
		}
		cout << ans << "\n";
	}

	return 0;
}


