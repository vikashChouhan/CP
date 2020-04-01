#include<bits/stdc++.h>
using namespace std;

#define li long int

struct node{
	int data;
	node* left = NULL;
	node *right = NULL;
};

node *insert(node *root,int data)
{
	if(root==NULL)
	{
		node *newnode = new node;
		newnode->data = data;
		root = newnode;	
		return root;
	}
	
	if(data<=root->data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	
	return root;
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void levelorder(node *root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *top = q.front();
		q.pop();
		if(top!=NULL)
		{
			q.push(top->left);
			q.push(top->right);
			cout<<top->data<<" ";	
		}	
	}	
}

int maxdepth(node *root,int &ans)
{
	if(root==NULL) return 0;
	
	int ldepth = maxdepth(root->left,ans);
	int rdepth = maxdepth(root->right,ans);
	
	ans = max(ans,1+ldepth+rdepth);
	if(ldepth>rdepth)
		return ldepth+1;
	else
		return rdepth+1;
}

void width(int *w,node *root,int h=0)
{
	if(root==NULL)
		return;
	
	w[h]++;
	width(w,root->left,h+1);
	width(w,root->right,h+1);
}

int atKdistance(node *root,int k)
{
	if(root==NULL)
		return -1;
	
	if(k==0)
	{
		cout<<root->data<<" ";
		return -1;
	}
	else
	{
		atKdistance(root->left,k-1);
		atKdistance(root->right,k-1);
	}
}
int main()
{
	node *root = NULL;
	for(int i=0;i<7;i++)
	{
		li x;
		cin>>x;
		root = insert(root,x);
	}
	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	levelorder(root);
	cout<<"\n";
	int ans=INT_MIN;
	cout<<maxdepth(root,ans);
	cout<<"\n"<<ans;
	
	int w[10]={0};
	cout<<"\n";
	width(w,root,0);
	for(int i=0;i<10;i++)
		cout<<w[i]<<" ";
	
	cout<<"\n";
	cout<<atKdistance(root,2);
}
