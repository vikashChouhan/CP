#include<bits/stdc++.h>
using namespace std;

#define li int
li tree[4194304];
li lazy[4194304];

void update(li i,li si,li se,li l,li r)
{

	if(lazy[i])
	{
		tree[i] = (se-si+1) - tree[i];
		if(si!=se)
		{
			lazy[2*i]=!lazy[2*i];
			lazy[2*i+1]=!lazy[2*i+1];
		}
		lazy[i]=0;
	}
		
		if(se<l || si>r || si>se)
		return;
	
	if(si>=l && se<=r)
	{
		tree[i] = (se-si+1) - tree[i];
		if(si!=se)
		{
			lazy[2*i]=!lazy[2*i];
			lazy[2*i+1]=!lazy[2*i+1];
		}
		lazy[i]=0;
	}
	else
	{
		li mid = (si+se)/2;
		update(2*i,si,mid,l,r);
	
		update(2*i+1,mid+1,se,l,r);
		
		tree[i] = tree[2*i]+tree[2*i+1];
	}
	
}


li query(li i,li si,li se,li l,li r)
{

	if(lazy[i])
	{
		tree[i] = (se-si+1) - tree[i];
		if(si!=se)
		{
			lazy[2*i]=!lazy[2*i];
			lazy[2*i+1]=!lazy[2*i+1];
		}
		lazy[i]=0;
	}
	
	if (r< si || l > se)
		return -1;
	if(si>=l && se<=r)
		return tree[i];
	
	li mid = (si+se)/2;
	if(r<=mid)
		query(2*i,si,mid,l,r);
	else if(l>mid)
		query(2*i+1,mid+1,se,l,r);
	else
		return query(2*i,si,mid,l,r) + query(2*i+1,mid+1,se,l,r);
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	li n,m;
	cin>>n>>m;
	
	while(m--)
	{
		li type;
		cin>>type;
		if(type==0)
		{
			li l,r;
			cin>>l>>r;
			update(1,0,n-1,l-1,r-1);
		}
		else
		{
			li l,r;
			cin>>l>>r;
			cout<<query(1,0,n-1,l-1,r-1)<<"\n";
			
		}
	}
	
}
