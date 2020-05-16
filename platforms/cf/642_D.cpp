#include<bits/stdc++.h>
using namespace std;

#define LI long int

struct node {
	int l,r;
	int len;
	node(int L,int R,int Len) {
		l = L;
		r = R;
		len = Len;
	}
	
};

struct comp {
	int operator()(const node *a,const node *b) {
		if(a->len==b->len)
			return a->l > b->l;
		return a->len < b->len;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n+1]={0};
		priority_queue<node*,vector<node*>,comp> Q;
		Q.push(new node(1,n,n));
		int op=1;
		while(!Q.empty())
		{
			int l = Q.top()->l;
			int r = Q.top()->r;
			Q.pop();
			
			int idx = (l+r)/2;
			arr[idx] = op++;
			if(idx!=l)
				Q.push(new node(l,idx-1,idx-l));
			if(idx!=r)
				Q.push(new node(idx+1,r,r-idx));
			
		}
		
		for(int i=1; i<=n; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	return 0;
}


