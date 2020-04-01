#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next=NULL;
	node *prev=NULL;
}*head=NULL,*last=NULL;

void add(int x)
{
	node *newnode = new node;
	newnode->data = x;
	
	if(head==NULL)
		head=last=newnode;
	else
	{
		last->next = newnode;
		newnode->prev = last;
		last = newnode;
	}
}

void print()
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<"-->";
		p=p->next;
	}
	cout<<"NULL\n";
}

void deleteOne(int x)
{
	node *p = new node;
	p = head;
	while(p!=NULL && p->data!=x)
		p=p->next;
	
	if(p!=NULL)
	{
		if(p==head)
			head = head->next;
		else
		{
			if(p->next!=NULL)
				p->next->prev=p->prev;
			if(p->prev!=NULL)
				p->prev->next = p->next;
			
			if(p==last)
				last=last->prev;
		}
		delete p;
	}
}

void deleteAll(int x)
{
	node *p = new node;
	p = head;
	while(p!=NULL)
	{
		if(p->data == x)
		{
			node *temp = new node;
			temp = p;
			if(temp==head)
				head = head->next;
			else
			{
				if(temp->next!=NULL)
					temp->next->prev=temp->prev;
				if(temp->prev!=NULL)
					temp->prev->next = temp->next;
			
				if(temp==last)
					last=last->prev;
			}
			p = p->next;
			delete temp;
		}
		else
			p=p->next;
	}
}
int main()
{
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int t,v;
		cin>>t>>v;
		
		if(t==1)
			add(v);
		else if(t==2)
			deleteOne(v);
		else
			deleteAll(v);
		print();
	}
	

}
