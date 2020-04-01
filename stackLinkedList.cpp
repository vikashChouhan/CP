#include<iostream>
using namespace std;

struct node{
	int data;
	node *next=NULL;
};

node *push(node *head,int data)
{
	node *newnode = new node;
	newnode->data = data;
	if(head==NULL)
		head = newnode;
	else
	{
		newnode->next = head;
		head = newnode;
	}
	
	return head;
}

int pop(node *head)
{
	node *p = head;
	if(head==NULL)
		cout<<"underflow";
	else
	{
		head=head->next;
	}
	return p->data;
}

int top(node *head)
{
	if(head==NULL)
		return -1;
	else
	{
		return head->data;
	}
}

bool isempty(node *head)
{
	return head==NULL;
}
int main()
{
	node *head=NULL;
	head = push(head,1);
	head = push(head,2);
	head = push(head,39);
	
	cout<<top(head)<<"\n";
	cout<<boolalpha<<isempty(head);
	pop(head);
	cout<<"\n"<<top(head);
	
}
