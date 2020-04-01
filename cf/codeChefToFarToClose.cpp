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

void dfs(vli *graph,vli &E,li *height,li *first,li *parent,li *visited,li node,li h)
{
    first[node]=E.size();
    height[node]=h;
    E.push_back(node);
    visited[node]=1;
    for(auto x:graph[node])
    {
        if(!visited[x])
        {
        	parent[x]=node;
            dfs(graph,E,height,first,parent,visited,x,h+1);
            E.push_back(node);
        }
    }
}

void build(li *tree,vli &E,li *height,li i,li s,li e)
{
    if(s==e)
        tree[i]=E[s];
    else
    {
        li mid = (s+e)/2;
        build(tree,E,height,2*i,s,mid);
        build(tree,E,height,2*i+1,mid+1,e);
        tree[i] = height[tree[2*i]]<height[tree[2*i+1]]?tree[2*i]:tree[2*i+1];
    }
}

li query(li *tree,li i,li s,li e,li l,li r)
{
    if(l<=s && r>=e)
        return tree[i];
    else
    {
        li mid =(s+e)/2;
        if(r<=mid)  
            return  query(tree,2*i,s,mid,l,r);
        else if(l>mid)  
            return query(tree,2*i+1,mid+1,e,l,r);
        else
            return min(query(tree,2*i,s,mid,l,mid),query(tree,2*i+1,mid+1,e,mid+1,r));
    }
}

li find_min(vli &arr)
{
    sort(arr.begin(),arr.end());
    li ans = INT_MAX;
    for(li i=0;i<arr.size()-1;i++)
        ans = min(ans,abs(arr[i]-arr[i+1]));
    
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    li n;
    cin>>n;
    li a[n+1];
    REP(i,1,n+1)cin>>a[i];
    
    vli graph[n+1];
    REP(i,0,n-1)
    {
        li u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        
    }

    vli E;
    li height[n+1],first[n+1];
    li parent[n+1],visited[n+1]={0};
    dfs(graph,E,height,first,parent,visited,1,1);
    
    li tree[4*E.size()-1];
    build(tree,E,height,1,0,E.size()-1);
    
    li q;
    cin>>q;
    while(q--)
    {
        char type;
        li x,y;
        cin>>type>>x>>y;
        vli arr;
        li l = min(first[x],first[y]);
        li r = max(first[x],first[y]);
        li lca = query(tree,1,0,E.size()-1,l,r);
        
        li max_ele=INT_MIN,min_ele=INT_MAX;
        if(lca==x || lca==y)
        {
            li temp;
            if(lca==x)
                temp =y;
            else
                temp =x;
            
            while(temp!=lca)
            {
                arr.push_back(a[temp]);
                max_ele = max(max_ele,a[temp]);
                min_ele = min(min_ele,a[temp]);
                temp = parent[temp];
            }
            arr.push_back(a[lca]);
            max_ele = max(max_ele,a[lca]);
            min_ele = min(min_ele,a[lca]);
            
            
        }
        else
        {
            li temp = x;
            while(temp!=lca)
            {
                arr.push_back(a[temp]);
                max_ele = max(max_ele,a[temp]);
                min_ele = min(min_ele,a[temp]);
                temp = parent[temp];
            }
            arr.push_back(a[lca]);
            max_ele = max(max_ele,a[lca]);
            min_ele = min(min_ele,a[lca]);
            temp = y;
            while(temp!=lca)
            {
                arr.push_back(a[temp]);
                max_ele = max(max_ele,a[temp]);
                min_ele = min(min_ele,a[temp]);
                temp = parent[temp];

            }
        }
        
            
        if(type=='C')
            cout<<find_min(arr)<<"\n";
        else
            cout<<abs(max_ele-min_ele)<<"\n";
    }
    
}
