#include<bits/stdc++.h>

using namespace std;
#define li long int
#define ll long long
#define pi pair<int,int>
#define pli pair<long int,long int>
#define vi vector<int>
#define vli vector<long int>
#define vll vector<long long>
#define vpi vector<pair<int,int> >
#define vpli vector<pair<long int,long int> >
#define MOD 1000000007
#define ll long long
#define ull unsigned long long 
#define REP(i,init,n) for(li i=init;i<n;i++)
#define INF 0x3f3f3f3f
template<class T>
inline T MODIT(T x){ return (x%MOD+MOD)%MOD;}

inline int search(li *a,int start,int end,int n,li val)
{
	int ans=-1;
	
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(a[mid]>=val)
		{
			ans = mid;
			end = mid-1;
		}
		else
			start = mid+1;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   int n;
   cin>>n;
    while(n!=0)
    {
    	
    li a[n];
    REP(i,0,n)cin>>a[i];
    sort(a,a+n);
    li ans = 0;
    for(int i=0;i<n-2;i++)
    {
    	for(int j=i+1;j<n-1;j++)
    	{
    		int idx = search(a,j+1,n-1,n,a[i]+a[j]);
    		if(idx!=-1)
    		ans+=n-idx;
		}
	}
    cout<<ans<<"\n";
    
    cin>>n;
	}
}
