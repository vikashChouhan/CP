#include<bits/stdc++.h>
using namespace std;

#define li long int
#define MOD 1000000007

li F[300002]={0};
void init_F()
{
	F[1]=1;F[2]=1;
	for(li i=3;i<=300002;i++)
		F[i] = (F[i-1] + F[i-2])%MOD;
	
	for(li i=2;i<=300002;i++)
		F[i]= (F[i]+F[i-1])%MOD;
}
void build(li *tree,li *a,li i,li s,li e)
{
	if(s==e)
	{
		tree[i]=a[s];
	}
	else
	{
		li mid = (s+e)/2;
		build(tree,a,2*i,s,mid);
		build(tree,a,2*i+1,mid+1,e);
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}

void update(li *tree,li *lazy,li i,li s,li e,li l,li r)
{
	if(lazy[i]!=0)
	{
		tree[i]+=lazy[i];
		if(s!=e)
		{
			li mid = (s+e)/2;
			lazy[2*i] += F[mid-s+1];
			lazy[2*i+1] += F[e-s+1]-F[mid-s+1];
		}
		lazy[i]=0;
	}
	if(s>e || l<s || r>e) 
		return;
	
	if(l<=s && r>=e)
	{
		tree[i]+=F[e-s+1];
		if(s!=e)
		{
			li mid = (s+e)/2;
			lazy[2*i] += F[mid-s+1];
			lazy[2*i+1] += F[e-s+1]-F[mid-s+1];
		}
		return;
	}
	
	li mid = (s+e)/2;
	update(tree,lazy,2*i,s,mid,l,r);
	update(tree,lazy,2*i+1,mid+1,e,l,r);
	tree[i]=tree[2*i]+tree[2*i+1];
}
li query(li *tree,li *lazy,li i,li s,li e,li l,li r)
{
	if(lazy[i]!=0)
	{
		tree[i]+=lazy[i];
		if(s!=e)
		{
			li mid = (s+e)/2;
			lazy[2*i] += F[mid-s+1];
			lazy[2*i+1] += F[e-s+1]-F[mid-s+1];
		}
		lazy[i]=0;
	}
	
	if(l<=s && r>=e)
		return tree[i];
	else
	{
		li mid = (s+e)/2;
		if(r<=mid)
			return query(tree,lazy,2*i,s,mid,l,r);
		else if(l>mid)
			return query(tree,lazy,2*i+1,mid+1,e,l,r);
		else
		{
			return query(tree,lazy,2*i,s,mid,l,mid)+query(tree,lazy,2*i+1,mid+1,e,mid+1,r);
		}
	}
}

int main()
{
	li n,m;
	cin>>n>>m;
	li a[n+1];
	for(li i=1;i<=n;i++)cin>>a[i];
	
	init_F();
	li tree[n+1],lazy[n+1]={0};
	
	build(tree,a,1,1,n);
	while(m--)
	{
		int type;
		li l,r;
		cin>>type>>l>>r;
		if(type==1)
			update(tree,lazy,1,1,n,l,r);
		else
			cout<<query(tree,lazy,1,1,n,l,r)<<"\n";
		
		for(li i=1;i<4*n;i++)
			cout<<lazy[i]<<" ";
		cout<<"\n";
		for(li i=1;i<4*n;i++)
			cout<<tree[i]<<" ";
	}
}
