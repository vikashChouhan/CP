#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> >time;
	for(int i=0;i<n;i++)
	{
		int start,end;
		cin>>start>>end;
		time.push_back({end,start});
	}
	sort(time.begin(),time.end());
	int cnt=0;
	int prev=-1;
	for(int i=0;i<n;i++)
	{
		if(prev==-1 || time[i].second>=time[prev].first)
		{
			cnt++;
			prev=i;
		}
	}
	
	cout<<cnt;
}
