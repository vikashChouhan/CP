#include<bits/stdc++.h>

using namespace std;
#define li long int
#define ll long long
#define pi pair<int,int>
#define pli pair<long int,long int>
#define vi vector<int>
#define vli vector<long int>
#define vll vector<long long>
#define vpi vector<pair<int,int> >
#define vpli vector<pair<long int,long int> >
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define REP(i,init,n) for(li i=init;i<n;i++)
#define INF 0x3f3f3f3f
template<class T>
inline T MODIT(T x){ return (x%MOD+MOD)%MOD;}

struct node{
	int dir;
	ll le,val,dist;

	node(ll val,ll le,ll dist,int dir):val(val),le(le),dist(dist),dir(dir){}

};

struct cmp{
		bool operator()(const node &n1,const node &n2){
		return (n1.dist<n2.dist)||(n1.dist==n2.dist && (n1.dir<n2.dir||n1.dir!=n2.dir||n1.le<n2.le));
	}
};

inline ll solve(vpli *g,vpli *gs,li n,li s,li e){

	vll dist(n+1,LONG_MAX);
	priority_queue<node,vector<node>,cmp>Q;
	
	li start[n+1],last[n+1];
	for(li i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
		sort(gs[i].begin(),gs[i].end());
		
		start[i]=0;last[i]=g[i].size()-1;
	}

	dist[s]=0;
	Q.push(node(s,0,0,0));
	while(!Q.empty()){
		node top = Q.top();
		Q.pop();
		li u = top.val;
		li dir = top.dir;
		li le = top.le;
		
	//	cout<<u<<" ";
	//	if(u==e && dist[u][0]!=INT_MAX && dist[u][1]!=INT_MAX) 
	//		break;
		dist[u]=min(dist[u],top.dist);
		if(dir){
			li i;
			for(i=start[u];i<gs[u].size();i++){
				li v = gs[u][i].second;
				li w = gs[u][i].first;
				if(le<=w)
					break;
				else
					Q.push(node(v,w,top.dist+w,0));
			}
			start[u]=i;
		}
		else{
			li i;
			for(i=last[u];i>=0;i--){
				li v = g[u][i].second;
				li w = g[u][i].first;
				if(le>=w)
					break;
				else
					Q.push(node(v,w,top.dist+w,1));
			}
			last[u]=i;
		}
	}
	//cout<<"\n";
	return dist[e];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	
	li t;
	cin>>t;
	while(t--){
		li n,m;
		cin>>n>>m;
		
		vpli g[n+1],gs[n+1];
		REP(i,0,m){
			li u,v,z;cin>>u>>v>>z;
			g[u].push_back({z,v});
			g[v].push_back({z,u});
			gs[u].push_back({z,v});
			gs[v].push_back({z,u});
		}
		li source,sink;
		cin>>source>>sink;
		ll ans = solve(g,gs,n,source,sink);
		if(ans==LONG_MAX) cout<<"No Solution\n";
		else
			cout<<ans<<"\n";
	}

}

