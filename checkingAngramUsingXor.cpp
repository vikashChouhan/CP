#include<bits/stdc++.h>
using namespace std;

int main()
{
	//anagram
	// s1.size == s2.size
	// cnt of each element in both string must be same
	
	
	
	//won't work aa bb as anagram
	string s1,s2;
	cin>>s1>>s2;
	
	int ans = 0;
	if(s1.length()!=s2.length())
		cout<<"Not anagram";
	else
		for(int i=0;i<s1.length();i++)	
			ans = ans^int(s1[i])^int(s2[i]);
	if(ans)
		cout<<"Not anagram";
	else
		cout<<"anagram";
}
