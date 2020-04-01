#include<bits/stdc++.h>
using namespace std;

#define li long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    li n;
    cin>>n;
    li a[n];
    for(li i=0;i<n;i++)
        cin>>a[i];
    
    li l[n]={0},r[n]={0};
    vector<li>s;
    for(li i=0;i<n;i++)
    {
        while(!s.empty() && a[s.back()]>=a[i])
            s.pop_back();
        
        if(s.empty())
            l[i]=-1;
        else
            l[i]=s.back();
        
        s.push_back(i);
    }
    
    s.clear();
    for(li i=n-1;i>=0;i--)
    {
        while(!s.empty() && a[s.back()]>=a[i])
            s.pop_back();
        if(s.empty())
            r[i]=n;
        else
            r[i]=s.back();
        
        s.push_back(i);
    }
    
    
    li ans[n+1]={0};
    for(li i=0;i<n;i++)
    {
        li size = r[i]-l[i]-1;
        ans[size]=max(ans[size],a[i]);
    }
    
    for(li i=n-1;i>=1;i--)
        ans[i]=max(ans[i],ans[i+1]);
    
    for(li i=1;i<=n;i++)	
    	cout<<ans[i]<<" ";
    
}
