/*
finding mid point of linked list

slow pointer : increment by 1
fast pointer : increment by 2

by the fast pointer reached to end, slow pointer will reach to mid
*/

#include<iostream>
using namespace std;

struct node {
	int data;
	node *next=NULL;
};

node* addNode(node *head,int data)
{
	node *newnode = new node;
	newnode->data = data;
	if(head==NULL)
		newnode->next = NULL;
	else
		newnode->next = head;
		
	head = newnode;
	
	
	return head;
}

void printReverse(node *head)
{
	if(head!=NULL)
	{
		cout<<head->data<<" ";
		printReverse(head->next);
		
	}
}

node * findMidPoint(node *head)
{
	node *sp = head;
	node *fp = head;
	while(fp->next!=NULL && fp->next->next!=NULL)
	{
		sp = sp->next;
		fp = fp->next->next;
	}
	return sp;
}
int main()
{
	node *head=NULL;
	head = addNode(head,1);
	head = addNode(head,10);
	head = addNode(head,20);
	//head = addNode(head,30);
	
	
	printReverse(head);
	cout<<"\n";
	
	node *mid = findMidPoint(head);
	cout<<"mid point is "<<mid->data;
}


