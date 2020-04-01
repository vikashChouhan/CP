#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next=NULL;
	node *prev=NULL;
}*head=NULL,*mid=NULL;

void push(int val,int &size)
{
	node *newnode = new node;
	newnode->data = val; 
	if(head==NULL)
	{
		head = newnode;
		mid = newnode;
		size++;
	}
	else
	{
		newnode->next = head;
		newnode->next->prev = newnode;
		head = newnode;
		size++;
		
		if(size%2!=0)
		 mid = mid->prev;
	}
}

void pop(int &size)
{
	if(head!=NULL)
	{
		if(size%2!=0)
		mid = mid->next;
		
		node *temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	
}

void popMiddle(int &size)
{
	if(mid==NULL)
		return;
		
	node *temp = mid;
	if(size%2!=0)
		mid = mid->next;
	else
		mid = mid->prev;
	
	if(temp->next!=NULL)	
		temp->next->prev=temp->prev;
	
	if(temp->prev!=NULL)
		temp->prev->next = temp->next;
	
	if(temp->next==NULL && temp->prev==NULL)
		head = NULL;
	delete temp;
	size--;
}

void pushMiddle(int val,int &size)
{
	node *newnode = new node;
	newnode->data = val;
	
	newnode->next = mid;
	newnode->prev = mid->prev;
	if(mid->prev!=NULL)
		mid->prev->next = newnode;
	
	if(size%2==0)
		mid = newnode;
	
	size++;
}
int main()
{   //9 8 7 6 3
	int size=0;
	push(3,size);
	push(6,size);
	push(7,size);
	push(8,size);
	push(9,size);
	//pop(size);
	//pop(size);
	
	pushMiddle(4,size);
	pushMiddle(88,size);
	if(head!=NULL)
	cout<<"top ="<<head->data<<" mid="<<mid->data<<"\n";
	else
	cout<<"no data";
}
