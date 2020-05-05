#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n],mininf=INT_MAX,maxinf=INT_MIN;
		int infected=1;
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
			if(i==0) continue;
			if(arr[i]-arr[i-1]<=2)
				infected++;
			else
			{
				mininf = min(mininf, infected);
				maxinf = max(maxinf, infected);
				infected=1;
			}	
		}
		mininf = min(mininf, infected);
		maxinf = max(maxinf, infected);
		cout << mininf << " " << maxinf <<"\n";
	}

	return 0;
}


