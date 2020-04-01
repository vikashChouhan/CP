#include<iostream>
using namespace std;

struct node {
	int data;
	node *next = NULL;
	node *prev = NULL;
};

node *addNodeHead(node*head,int data)
{
	node *newnode = new node;
	newnode->data = data;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
}

void printList(node*head)
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

node * deleteNode(node *head,int data)
{
	node *p = new node;
	p = head;
	while(p!=NULL && p->data!=data)
		p=p->next;
	
	if(p==NULL)
	{
		cout<<"Node not found";
	}
	else
	{
		
		if(p->prev!=NULL)
			p->prev->next = p->next;
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		
		if(p->next!=NULL)
			p->next->prev = p->prev;
	
		delete p;
	}
	return head;
}

int main()
{
	node *head=NULL;
	head = addNodeHead(head,1);
	head = addNodeHead(head,10);
	head = addNodeHead(head,20);
	head = addNodeHead(head,30);
	head = addNodeHead(head,40);
	
	printList(head);
	head = deleteNode(head,40);
	cout<<"\n";
	printList(head);
}
