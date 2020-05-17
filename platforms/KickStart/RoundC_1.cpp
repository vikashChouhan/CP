#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

    int T,t=1;
    cin >> T;
    while(t<=T)
    {
        int n, k;
        cin >> n >> k;
        
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(A[i]==k)
            {
                int j = i;
                int temp = k;
                while(j<n)
                {
                    if(A[j]==temp)
                    {
                        temp--;
                        j++;
                    }
                    else
                        break;
                }
                if(temp==0)
                    ans++;
                i = j-1;
            }
        }
        cout << "Case #" << t << ": "<< ans <<"\n";
        t++;
    }

	return 0;
}


