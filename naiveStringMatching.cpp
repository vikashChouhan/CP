#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string text;
	cin>>text;
	string pattern;
	cin>>pattern;
	
	int pos=-1,i=0,j=0;
	while(i<text.length()){
		int temp=i;
		while(text[temp]==pattern[j] && j<pattern.length()){
			temp++;j++;
		}
		if(j==pattern.length()){
			break;
		}
		else{
			j=0;
		}
		i++;
	}
	cout<<"found at"<<i;

}

