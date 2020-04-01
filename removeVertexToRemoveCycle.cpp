#include<bits/stdc++.h>
using namespace std;
#define li long int
#define vli vector<li>
#define MAX 100001

inline int solve(vli *g,li p,li u,bitset<MAX>&cycle,li *parent,int *vis,int *discovered,int &hascycle){
	
	
	if(vis[u]) return 0;
	
	if(discovered[u]){
	    bitset<MAX>bitemp;
    	li temp = p;
		bitemp.set(p);
		bitemp.set(u);
		while(temp!=u){
			bitemp.set(temp);
			temp = parent[temp];
		}
		
		if(cycle.count()==0){
		    cycle=bitemp;
			hascycle=1;
		}
		else{
			
			cycle = cycle&bitemp;
			if(cycle.count()==0 || (cycle.count()==1&&cycle[0])) return -1;
		}
		
		return 0;
	}
	discovered[u]=1;
	parent[u]=p;
	for(li x:g[u]){
		if(x==parent[u]) continue;
		
		if(solve(g,u,x,cycle,parent,vis,discovered,hascycle)==-1)
			return -1;
	}
	vis[u]=1;
	
	return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		
		li n,m;
		cin>>n>>m;
		
		vli g[n+1];
		for(li i=0;i<m;i++){
			li u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		int discovered[n+1]={0},vis[n+1]={0};
		li parent[n+1]={0};
		bitset<MAX>cycle;
		int hascycle=0,cnt=0;
		int ans=0;
		for(li i=1;i<=n;i++){
			if(vis[i]) continue;
			ans=solve(g,-1,i,cycle,parent,vis,discovered,hascycle);
			
			if(ans==-1) break;
			else if(hascycle){
			    if(cnt==1){
			        ans=-1;
			        break;
			    }
			    cnt++;
			}
			
			hascycle=0;
			//cycle.reset();
		}
		
		
		if(ans==-1 || cnt==0)
			cout<<-1<<"\n";
		else
			for(li i=1;i<cycle.size();i++){
				
				if(cycle[i]){
					cout<<i<<"\n";
					break;
				}
			}
		
	}

}

