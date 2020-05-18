#include<bits/stdc++.h>
using namespace std;

int mm[2*100*100000+1];
long int countSum(int *a, int n)
{
    
    long long currsum = 0, res=0;
    long long mxpos=0,mxneg=0;
    
    for(int i=0; i<n; i++)
        if(a[i]>0)
            mxpos+=a[i];
        else 
            mxneg+=abs(a[i]);
    
    
    memset(mm,0,sizeof mm);
    mm[mxneg]++;
    for(int i=0; i<n; i++)
    {
        currsum+=a[i];
        
        for(int j=0; j*j<=mxpos; j++)
        {
            if(mxneg+currsum-j*j>=0)
                res+=mm[mxneg+currsum-j*j];
                
        	
		}
        mm[mxneg+currsum]++;
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

    int T;
    cin >> T;
    
    for(int test=1; test<=T; test++)
    {
        int n;
        cin >> n;
        int a[n];
        long int maxno=INT_MIN;
        for(int i=0; i<n; i++)
		{
			cin >> a[i];
		}
        
        long long ans = 0;
        ans = countSum(a,n);
            
        
        cout << "Case #"<<test<<": "<<ans<<"\n";
    }

	return 0;
}


