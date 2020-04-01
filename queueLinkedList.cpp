#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *next=NULL;
}*front=NULL,*rear=NULL;

void push(int val)
{
	node *newnode = new node;
	newnode->val = val;
	if(front==NULL)
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

int  pop()
{
	cout<<"f="<<front->val<<"\n";
	if(front!=NULL)
	{
		int temp= front->val;
		node *p = front;
		if(front->next!=NULL)
		{
			front = front->next;
			delete p;	
		}
		else
			{
				front = rear =NULL;
			}
		
		return temp;
	}
	else
	{
		cout<<"No data to delete, underflow";
		return -1;
	}
}

int top()
{
	if(front!=NULL)	
		return front->val;
	else
		cout<<"No data";
	return -1;
}
int main()
{
	push(2);
	push(5);
	push(1);
	cout<<top()<<"\n";
	pop();
	cout<<top()<<"\n";
	pop();
	cout<<top()<<"\n";
	pop();
	cout<<top()<<"\n";
}
