#include<bits/stdc++.h>
using namespace std;

void reverse(int *a,int i,int size)
{
	if(i<size)
	{
		int temp=a[i];
		reverse(a,i+1,size);
		a[size-1-i]=temp;
	}
}

void reverseFirst(queue<int>&q,int num)
{
	if(!q.empty() && q.size()>num && num>0)
	{
		int temp = q.front();
		q.pop();
		reverseFirst(q,num-1);
		q.push(temp);
	}
}
void reverseLast(queue<int>&q,int num)
{
	if(!q.empty())
	{
		while(q.size()>num)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
			num++;
		}
	}
}
int main()
{
	int size;
	cin>>size;
	queue<int>q;
	for(int i=0;i<size;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	int num;
	cin>>num;
	
	/*
	
	1 2 3 4 5 --> 3 2 1 4 5
	
	*/
	reverseFirst(q,num);
	reverseLast(q,num);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}
