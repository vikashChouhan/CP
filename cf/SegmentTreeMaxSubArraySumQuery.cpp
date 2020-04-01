#include<bits/stdc++.h>
using namespace std;

#define li long int
struct node {
	li data;
	node*left=NULL;
	node*right=NULL;
	pair<li,li>range;
}*root=NULL;

node *getnode()
{
	node *newnode = new node;
	return newnode;
}
node* buildTree(node *root,li *a,li start,li end)
{
	root = getnode();
	if(start==end)
	{
		root->data = a[start];
		root->range = {start,start};
		return root;
	}
	
	li  mid = (start+end)/2;
	root->left = buildTree(root->left,a,start,mid);
	root->right = buildTree(root->right,a,mid+1,end);
	
	pair<li,li> Lrange = root->left->range;
	pair<li,li> Rrange = root->right->range;
	li ldata = root->left->data;
	li rdata = root->right->data;
	if(Lrange.second+1==Rrange.first && ldata+rdata>max(ldata,rdata))
	{
		root->range = {Lrange.first,Rrange.second};
		root->data = root->left->data + root->right->data;
	}
	else
	{
		if(root->left->data>root->right->data)
		{
			root->data = root->left->data;
			root->range = {Lrange.first,Lrange.second};
		}
		else
		{
			root->data = root->right->data;
			root->range = {Rrange.first,Rrange.second};
		}
	}
	return root;
}

node * Query(node *root,li rl,li rr,li l,li r)
{
	li mid = (rl+rr)/2;
	if(rl==l && rr==r)
	{
		return root;
	}
	else if(mid+1<=l && mid+1<=r)
		Query(root->right,mid+1,rr,l,r);
		
	else if(l<=mid && r<=mid)
		Query(root->left,rl,mid,l,r);
		
	else if(l<=mid && r>=mid+1)
	{
		node *n1 = Query(root->left,rl,mid,l,mid);
		node *n2 = Query(root->right,mid+1,rr,mid+1,r);
		
		node *newnode = getnode();
		if(n1->range.second+1 == n2->range.first && n1->data+n2->data>=max(n1->data,n2->data))
		{
			newnode->data = n1->data+n2->data;
			newnode->range = {n1->range.first,n2->range.second};
			return newnode;
		}
		else
		{
			newnode->data = max(n1->data,n2->data);
			if(n1->data>n2->data)
				newnode->range=n1->range;
			else
				newnode->range = n2->range;
			return newnode;
		}
	}
	
}
int main()
{
	li n;
	cin>>n;
	li a[n];
	for(li i=0;i<n;i++)cin>>a[i];
	
	root = buildTree(root,a,0,n-1);
	
	li m;
	cin>>m;
	while(m--)
	{
		li l,r;
		cin>>l>>r;
		cout<<Query(root,0,n-1,l-1,r-1)->data<<"\n";
	}	
}
