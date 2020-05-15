#include<bits/stdc++.h>
using namespace std;

#define LI long int


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n],b[n];
		for(int i=0; i<n; i++) cin >> a[i];
		for(int j=0; j<n; j++) cin >> b[j];
		sort(a,a+n);
		sort(b,b+n);
		
		int i=0,j=n-1;
		while(k--)
		{
			if(b[j]<a[i]) break;
			
			if(b[j]>a[i])
			{
				int x  =a[i];
				a[i] = b[j];
				b[j] = x;
			}
			i++;
			j--;
		}
		int sum=0;
		cout << accumulate(a,a+n,sum) << "\n";
	}

	return 0;
}


