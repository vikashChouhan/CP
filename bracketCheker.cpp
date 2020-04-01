#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	char stack[s.length()+1];
	int size=0;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
		{
			stack[size]=s[i];
			size++;
		}
		else
		{
			if(size>0 && s[i]==stack[size-1])
				size--;
			else
				break;
		}
		
	}
	
	if(size>0)
		cout<<"Invalid";
	else
		cout<<"valid";
}
