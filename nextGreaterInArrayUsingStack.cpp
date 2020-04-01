#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<int>s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(!s.empty() && s.top()<x)
		{
			cout<<s.top()<<"->"<<x;
			s.pop();
		}
		else
		{
			s.push(x);
		}
	}
	
	if(!s.empty())
	{
		while(!s.empty())
		{
			int t = s.top();
			s.pop();
			if(s.size()==1)
			{
				cout<<s.top()<<"->"<<-1<<"\n";
				break;
			}
			if(t>s.top())
			{
				cout<<s.top()<<"->"<<t<<"\n";
				s.push(t);
				s.push(t);
			}
			else
			{
				cout<<s.top()<<"->"<<-1<<"\n";
				s.pop();
				s.push(t);
			}
			
			
		}
	}
}
