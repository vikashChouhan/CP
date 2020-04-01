/*
 * road.cpp
 * 
 * 
 * 
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector< vector<pii> > graph;


int findPar(int x,int *parent)
{
    if(parent[x]!=x)
        parent[x] = findPar(parent[x],parent);
    
    return parent[x];
}


struct edge{
    ll u,v,w;
    edge(int U, int V, int W){
        u=U; v=V; w=W;
    }
    bool operator<(const edge &e1){
        if(e1.w > w)return 1;
        else return 0;
    }
};

#define INF 1000000000000000000ll

vector< edge > edgeList;
ll dist[20004];
int edgeChosen[20004];

int main(){
    
    
    int t;
    scanf("%d",&t);
    while(t--){
        edgeList.clear();
        graph.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++){
            graph.push_back(vector<pii>());
            dist[i] = INF;
            edgeChosen[i] = 0;
        }
        for(int i=0; i<m; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(pii(v,w));
            graph[v].push_back(pii(u,w));
            edgeList.push_back(edge(u,v,w));
        }
        sort(edgeList.begin(), edgeList.end());
        ll mst = 0;
        int cnt = 0;
        int parent[n];
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0; i<m; i++){
            int u = edgeList[i].u;
            int v = edgeList[i].v;
            if(findPar(u,parent)==findPar(v,parent))continue;
            else{
                parent[parent[u]] = findPar(v,parent);
                mst+=edgeList[i].w;
                cnt++;
            }
        }
        
        if(cnt!=n-1){
            printf("NO\n");
            continue;
        }
        //cout<<mst<<endl;

        priority_queue< pii, vector<pii>, greater<pii> > pq;
        pq.push(pii(0,0));
        dist[0] = 0;
        int vis[n]={0};
        while(!pq.empty()){
            int u = pq.top().second;
            ll d = pq.top().first;
            //cout<<u<<" "<<d<<" "<<edgeChosen[u]<<endl;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            int len = graph[u].size();
            for(int i=0; i<len; i++){
                int v = graph[u][i].first;
                ll w = graph[u][i].second;
                if(!vis[v] && dist[v] > w + d ){
                    dist[v] = w+d;
                    pq.push(pii(w+d,v));
                    edgeChosen[v] = w;
                }
                else if(dist[v] == w+d && w<edgeChosen[v]){
                    edgeChosen[v] = w;   
                }
            }
        }
        ll mdt = 0;
        for(int i=0; i<n; i++){
            mdt += edgeChosen[i];
        }
        //cout<<mdt<<endl;
        if(mdt==mst){
            printf("YES\n");
        } 
        else printf("NO\n");

    }

    
}

