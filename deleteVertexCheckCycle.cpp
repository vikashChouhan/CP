#include<bits/stdc++.h>

using namespace std;
#define li long int
#define vli vector<li>

int hasCycle(vli *g,li u,li p,li *par,int *vis,vector<li>&comp,int &res){
	
	if(vis[u]==2) return 0;
	
	if(vis[u]==1){
		res=1;
		return 0;
	}
	comp.push_back(u);
	vis[u]=1;
	par[u]=p;
	for(auto x:g[u]){
		if(par[u]==x) continue;
		
		hasCycle(g,x,u,par,vis,comp,res);
	}
	vis[u]=2;
	return 0;
}

int checkCycle2(vli *g,li u,li p,li ex,int *vis,li *par)
{
	if(vis[u]==2) return 0;
	
	if(vis[u]==1) return 1;
	
	vis[u]=1;
	par[u]=p;
	for(auto x:g[u]){
		if(par[u]==x || x==ex)continue;
		//cout<<"<"<<u<<","<<x<<">\n";
		//cout<<"vis["<<x<<"]="<<vis[x]<<"\n";
		if(checkCycle2(g,x,u,ex,vis,par)==1)
			return 1;
	}
	vis[u]=2;
	return 0;
}
li getminvertex(vli *g,vector<li>&comp,li n)
{
	li minv=INT_MAX;
	int vis[n+1];
	li parent[n+1];
	for(li i=0;i<comp.size();i++){
		memset(vis,0,sizeof vis);
		memset(parent,0,sizeof parent);
		li start;
		if(i==0)	
			start=comp[1];
		else
			start = comp[0];
		//cout<<"s="<<start<<"exp="<<comp[i]<<"\n";
		if(!checkCycle2(g,start,-1,comp[i],vis,parent)){
			minv = min(minv,comp[i]);
		//	cout<<comp[i]<<"\n";
		}
		
	}
	return minv==INT_MAX?-1:minv;
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
		
		int vis[n+1]={0};
		li parent[n+1]={0};
		
		vector<vector<li> >compcycle;
		for(li i=1;i<=n;i++){
		    if(vis[i]==2) continue;
			vector<li>comp;
			int res=0;
			hasCycle(g,i,-1,parent,vis,comp,res);
			if(res){
				compcycle.push_back(comp);
				if(compcycle.size()==2){
				    compcycle.clear();
				    break;
				}
			}
			
		}
		
		//for(auto x:compcycle[0])
		//	cout<<x<<" ";
		//cout<<"\n";
		
		if(compcycle.empty()) cout<<"-1\n";
		else{
			cout<<getminvertex(g,compcycle[0],n)<<"\n";
		}
	}

}

