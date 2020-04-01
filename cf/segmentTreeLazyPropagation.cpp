#include<bits/stdc++.h>
using namespace std;

void build(int *tree,int *a,int i,int si,int se)
{
	if(si==se)
		tree[i] = a[si];
	else
	{
		int mid=(si+se)/2;
		build(tree,a,2*i,si,mid);
		build(tree,a,2*i+1,mid+1,se);
		
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}

void update(int *tree,int *a,int *lazy,int i,int si,int se,int l,int r,int val)
{

	if(lazy[i]!=0)
	{
		tree[i]+=(se-si+1)*lazy[i];
		if(si!=se)
		{
			lazy[2*i]+=lazy[i];
			lazy[2*i+1]+=lazy[i];
		}
		lazy[i]=0;
	}
	
		if(se<l || si>r || si>se)
		return;
	
	if(si>=l && se<=r)
	{
		tree[i] += (se-si+1)*val;
		if(si!=se)
		{
			lazy[2*i]+=val;
			lazy[2*i+1]+=val;
		}
		lazy[i]=0;
	}
	else
	{
		int mid = (si+se)/2;
			update(tree,a,lazy,2*i,si,mid,l,r,val);
	
			update(tree,a,lazy,2*i+1,mid+1,se,l,r,val);
		tree[i]=tree[2*i]+tree[2*i+1];
	}
	
}


int query(int *tree,int *a,int *lazy,int i,int si,int se,int l,int r)
{
	if(si>se || l>se || r<si)
		return 0;
	
	if(lazy[i]!=0)
	{
		tree[i]+=(se-si+1)*lazy[i];
		if(si!=se)
		{
			lazy[2*i]+=lazy[i];
			lazy[2*i+1]+=lazy[i];
		}
		lazy[i]=0;
	}
	
	if(si>=l && se<=r)
		return tree[i];
	
	int mid = (si+se)/2;
	if(r<=mid)
		query(tree,a,lazy,2*i,si,mid,l,r);
	else if(l>mid)
		query(tree,a,lazy,2*i+1,mid+1,se,l,r);
	else
		return query(tree,a,lazy,2*i,si,mid,l,mid) + query(tree,a,lazy,2*i+1,mid+1,se,mid+1,r);
	
}

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		a[i]=0;
	
	int tree[4*n]={0};
	build(tree,a,1,1,n);
	
	int lazy[4*n]={0};
	int q;
	cin>>q;
	while(q--)
	{
		char type;
		cin>>type;
		if(type=='u')
		{
			int l,r,val;
			cin>>l>>r>>val;
			update(tree,a,lazy,1,1,n,l,r,val);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<query(tree,a,lazy,1,1,n,l,r)<<"\n";
			
		}
	}
	
}
