#include<iostrem>
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
	if(head->next!=NULL)
	{
		printReverse(head->next);
		cout<<head->data<<" ";
	}
}
int main()
{
	node *head=NULL;
	head=addNode(head,1);
	head = addNode(head,10);
	head = addNode(head,20);
	head = addNode(head,30);
	
	printReverse(head);
}
