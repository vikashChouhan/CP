#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    cin>>size;
    priority_queue<int,vector<int>,greater<int> >Q;
    for(int i=0;i<size;i++){
    	int x;
    	cin>>x;
    	Q.push(x);
	}
	int ans = 0;
	while(!Q.empty()){
		int v1 = Q.top();
		Q.pop();
		int v2 = Q.top();
		Q.pop();
		ans += v1+v2;
		Q.push(v1+v2);
		if(Q.size()==1) break;
	}
	cout<<ans<<"\n";

}

