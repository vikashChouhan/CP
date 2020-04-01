#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
};

node* addNode(node *head,int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->next = head;
	head = newnode;
	head = newnode;
	
	return head;
}

void printReverse(node *head)
{
	if(head!=NULL)
	{
		printReverse(head->next);
		cout<<head->data<<" ";
	}
}

void reverseList(node *head,node *nextnode,node *prev)
{
	/*
	if(nextnode!=NULL)
	{
		if(nextnode->next!=NULL)
			reverseList(head,nextnode->next,nextnode);
		else
			head = nextnode;
		nextnode->next = prev;
	}
	
	if(prev==head)
		nextnode->next = NULL;*/
}

void deleteNode(node *head,int val)
{
	node *prev = head;
	node *nextnode = head->next;
	while(nextnode!=NULL)
	{
		if(nextnode->data == val)
		{
				node *temp = nextnode;
				prev->next = nextnode->next;
				nextnode = prev->next;
				delete temp;
		}
		else
		{
			prev = nextnode;
			nextnode = nextnode->next;
		}
	}
	//if(nextnode==NULL)
	//	cout<<"Not found\n";
	
}
int main()
{
 	
	node *head=NULL;
	head = addNode(head,1);
	head = addNode(head,10);
	head = addNode(head,20);
	head = addNode(head,30);
	head = addNode(head,40);
	head = addNode(head,20);
	head = addNode(head,30);
	
	printReverse(head);
	cout<<"\n";
	//reverseList(head,head->next,head);
	
	deleteNode(head,20);
	printReverse(head);
}
