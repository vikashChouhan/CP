#include<bits/stdc++.h>
using namespace std;

#define li long long int 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	li n;
	cin>>n;
	li x;
	li ncnt=0;
	li pcnt=0;
	li zcnt=0;
	li cost =0;
	li minpos=INT_MAX;
	li maxneg=INT_MIN;
	for(li i=0;i<n;i++)
	{
		cin>>x;
		if(x!=0)
		cost += abs(x)-1;
		
		if(x<0)
			ncnt++;
		else if(x>0)
			pcnt++;
		else
			zcnt++;
			
		if(x>0)
			minpos = min(minpos,x);
		else if(x<0)
			maxneg = max(maxneg,x);
	}
	
	if(ncnt&1)
	{
		if(zcnt)
			cost+=zcnt;
		else if(minpos!=INT_MAX)
		{
			cost -= min(minpos,-maxneg) -1;
			cost += min(minpos,-maxneg) +1;
		}
		else
			cost+=2;
	}
	else
		cost+=zcnt;
	cout<<cost;
}
