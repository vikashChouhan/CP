#include<bits/stdc++.h>
using namespace std;

typedef long int ll;
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[n+1];
		for(int i=1; i<=n; i++)
			cin>>arr[i];
		
		vector<set<int>> groups;
		int x,y;
		int parent[n+1]={0};
		
		for(int i=0; i<m; i++)
		{
			cin>>x>>y;
			if(parent[x]==0 && parent[y]==0)
			{
				groups.push_back(set<int>());
				groups[groups.size()-1].insert(x);
				groups[groups.size()-1].insert(y);
				parent[x] = groups.size();
				parent[y] = groups.size();
			}
			else if(parent[x]!=0 && parent[y]==0)
			{
				groups[parent[x]-1].insert(y);
				parent[y] = parent[x];	
			}
				
			else if(parent[x]==0 && parent[y]!=0)
			{
				groups[parent[y]-1].insert(x);
				parent[x] = parent[y];	
			}
			else if(parent[x]!=parent[y])
			{
				set<int> &s1 = groups[parent[x]-1];
				set<int> &s2 = groups[parent[y]-1];
				for(int each: s2)
				{
					s1.insert(each);
					parent[each] = parent[x];
				}
				s2.clear();
			}
			
		}
	
		ll ans = 0;
		if(m!=0)
		{
			for(set<int> &eachSet: groups)
			{
				for(int idx: eachSet)
				{
					while(arr[idx]!=idx && eachSet.find(arr[idx])!=eachSet.end())
						swap(arr[idx],arr[arr[idx]]);
				}
			}
			
			
			for(set<int> &eachSet: groups)
			{
				for(int idx: eachSet)
				{
					while(arr[idx]!=idx)
					{
						while(parent[idx]==parent[arr[idx]])
							ans++;
						swap(arr[idx],arr[arr[idx]]);
					}
				}
			}
		}
		
		
		for(int i=1; i<=n; i++)
		{
			while(arr[i]!=i)
			{
				
				if(parent[i]!=parent[arr[i]] or parent[i]==0)
					ans++;
				swap(arr[i],arr[arr[i]]);
			}
		} 
		cout<<ans<<"\n";
	}

	return 0;
}


