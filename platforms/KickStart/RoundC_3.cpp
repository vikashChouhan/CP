#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>pfsq;
void init()
{
    for(ll i=0; i*i<=10000000; i++)
        pfsq.emplace_back(i*i);
}

ll countSum(int *a, int n)
{
    
    ll currsum = 0, res=0;
    unordered_map<ll,ll>mm;
    for(int i=0; i<n; i++)
    {
        currsum+=a[i];
        
        for(ll sum: pfsq)
        {
			res+=mm[currsum-sum];
			if(currsum==sum) res++;
		}
        mm[currsum]++;
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

    int T;
    cin >> T;
    
    init();
    for(int test=1; test<=T; test++)
    {
        int n;
        cin >> n;
        int a[n];
        
        for(int i=0; i<n; i++)
			cin >> a[i];
		
        
        ll ans = countSum(a,n);
        cout << "Case #"<<test<<": "<<ans<<"\n";
    }

	return 0;
}


