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

void updateLR(li *tree,li *lazy,li *a,li i,li s,li e,li l, li r,li val)
{
    if(lazy[i]!=0)
    {
        tree[i]+=(e-s+1)*lazy[i];
        if(s!=e)
        {
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>r || s>r || l>e)
        return;
    
    if(l<=s && r>=e)
    {
    	if(val)
        	tree[i]+=(e-s+1)*val;
        else
        	tree[i]=0;
        if(s!=e)
        {
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    else
    {
        li mid = (s+e)/2;
        updateLR(tree,lazy,a,2*i,s,mid,l,r,val);
        updateLR(tree,lazy,a,2*i+1,mid+1,e,l,r,val);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    
}


li getval(li *tree,li *lazy,li i,li s,li e,li idx)
{
	 if(lazy[i]!=0)
    {
        tree[i]+=(e-s+1)*lazy[i];
        if(s!=e)
        {
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    
	if(s==e)
		return tree[i];
	else
	{
		li mid = (s+e)/2;
		if(idx<=mid)
			return getval(tree,lazy,2*i,s,mid,idx);
		else
			return getval(tree,lazy,2*i+1,mid+1,e,idx);
	}
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);cout.tie(NULL);
    
    li n;
    cin>>n;
    li a[n+1];
    REP(i,1,n+1)cin>>a[i];
    
    li t2[4*n]={0},lazy2[4*n]={0};
    li t3[4*n]={0},lazy3[4*n]={0};
    li t5[4*n]={0},lazy5[4*n]={0};
    li m;
    cin>>m;
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            li l,r,p;
            cin>>l>>r>>p;
            if(p==2) updateLR(t2,lazy2,a,1,1,n,l,r,1);
            if(p==3) updateLR(t3,lazy3,a,1,1,n,l,r,1);
            if(p==5) updateLR(t5,lazy5,a,1,1,n,l,r,1);
        }
        else
        {
            li idx,val;
            cin>>idx>>val;
            a[idx]=val;
            updateLR(t2,lazy2,a,1,1,n,idx,idx,0);
            updateLR(t3,lazy3,a,1,1,n,idx,idx,0);
            updateLR(t5,lazy5,a,1,1,n,idx,idx,0);
            
        }
    }
    
    for(li i=1;i<=n;i++)
    {
		li cnt2 = getval(t2,lazy2,1,1,n,i);
		li cnt3 = getval(t3,lazy3,1,1,n,i);
		li cnt5 = getval(t5,lazy5,1,1,n,i);
		
		while(cnt2-- && a[i]%2==0) a[i]/=2;
		while(cnt3-- && a[i]%3==0) a[i]/=3;
		while(cnt5-- && a[i]%5==0) a[i]/=5;
		cout<<a[i]<<" "<<cnt2<<" "<<cnt3<<" "<<cnt5<<"\n";
	}
		
}
