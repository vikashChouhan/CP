#include<bits/stdc++.h>
using namespace std;

#define LI long int

LI height(LI n)
{
	LI s=0,e=30000;
	LI h=0,a;
	while(s<=e)
	{
		LI m = s + (e-s)/2;
		
		LI cnt = (m*(3*m+1))/2;
		if(cnt < n)
		{
			h = m;
			s = m+1;
		}
		else if(cnt==n)
		{
			h = m;
			break;
		}
		else
			e = m-1;
	}
	return h;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		LI n;
		cin >> n;		
		int ans=0;
		LI h = height(n);
		while(h)
		{
			//cout << "h="<<h<<"\n";
			ans++;
			n-= (h*(3*h+1))/2;
			h = height(n);
		}
		cout << ans <<"\n";
	}

	return 0;
}


