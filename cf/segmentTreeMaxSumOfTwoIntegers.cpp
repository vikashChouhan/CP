#include<bits/stdc++.h>
using namespace std;

#define li long int

struct node{
	li max=-1;
	li smax=-1;
};

void update_node(node *tree,li i)
{
	if(tree[2*i].max>tree[2*i+1].max)
		{
			tree[i].max = tree[2*i].max;
			tree[i].smax = max(tree[2*i].smax,tree[2*i+1].max);
		}
		else
		{
			tree[i].max = tree[2*i+1].max;
			tree[i].smax = max(tree[2*i+1].smax,tree[2*i].max);
		}
		
}
void build(node *tree,li *a,li i,li s,li e)
{
	if(s==e)
	{
		tree[i].max=a[s];
	}
	else
	{
		li mid = (s+e)/2;
		build(tree,a,2*i,s,mid);
		build(tree,a,2*i+1,mid+1,e);
		
		tree[i].max = max(tree[2*i].max,tree[2*i+1].max);
		tree[i].smax = max(min(tree[2*i].max,tree[2*i+1].max),max(tree[2*i].smax,tree[2*i+1].smax));
	}
}

void update(node *tree,li *a,li i,li s,li e,li idx,li val)
{
	if(s>e)
		return;
	
	if(s==e)
	{
		tree[i].max = max(tree[i].max,val);
	}
	else
	{
		li mid = (s+e)/2;
		if(idx<=mid)
			update(tree,a,2*i,s,mid,idx,val);
		else 
			update(tree,a,2*i+1,mid+1,e,idx,val);
		
		tree[i].max = max(tree[2*i].max,tree[2*i+1].max);
		tree[i].smax = max(min(tree[2*i].max,tree[2*i+1].max),max(tree[2*i].smax,tree[2*i+1].smax));
	}
}


node query(node *tree,li i,li s,li e,li l,li r)
{
	node n3;
	if(l>e || r<s || s>e)
		return n3;
	
	if(l<=s && r>=e)
		return tree[i];
	
	li mid=(s+e)/2;
	
	if(r<=mid)
		return query(tree,2*i,s,mid,l,r);
	else if(l>mid)
		return query(tree,2*i+1,mid+1,e,l,r);
	else
	{
		node n1 = query(tree,2*i,s,mid,l,mid);
		node n2 = query(tree,2*i+1,mid+1,e,mid+1,r);
		
		n3.max = max(n1.max,n2.max);
		n3.smax = max(min(n1.max,n2.max),max(n1.smax,n2.smax));
		return n3;	
	}
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);
	
	li n;
	cin>>n;
	li a[n+1];
	for(li i=1;i<=n;i++)cin>>a[i];
	
	node tree[4*n];
	build(tree,a,1,1,n);
	
	li q;
	cin>>q;
	while(q--)
	{
		char type;
		cin>>type;
		li l,r;
		cin>>l>>r;
		if(type=='U')
			update(tree,a,1,1,n,l,r);
		else
		{
			node tt = query(tree,1,1,n,l,r);
			cout<<tt.max+tt.smax<<"\n";
		}
	}
}
