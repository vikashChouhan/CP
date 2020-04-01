#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007

template <typename T>
void SWAP(T &_a, T &_b){ T t = _a;_a = _b; _b = t;}

template <typename T>
ostream &operator<<(ostream &stream, const vector<T>& inp_)
{ for(auto &x: inp_)stream << x << " "; stream << "\n";
return stream;}

template <typename T,typename T_>
ostream &operator<<(ostream &stream, const pair<T,T_>& inp_)
{stream << "(" << inp_.first << "," << inp_.second <<") ";
return stream;}

template <typename T>
T GCD(T a, T b)
{T temp;while(b>0){temp = b;b = a%b;a = temp;}
return a;}


void dks(VEC(PAIR(LI,LI))*graph, LI s, LI d, LI *parent)
{
	priority_queue<PAIR(LI,LI),VEC(PAIR(LI,LI)),greater<PAIR(LI,LI)> >Q;
	Q.push({0,1});
	
	int vis[d+1] = {0};
	LI dist[d+1];
	fill(dist,dist+d+1,INT_MAX);
	
	while(!Q.empty())
	{
		LI u = Q.top().second;
		Q.pop();
		
		if(u==d)
			break;
		vis[u]=1;
		for(auto &x:graph[u])
		{
			if(!vis[x.second] && dist[u]+x.first < dist[x.second])
			{
				dist[x.second] = dist[u]+x.first;
				Q.push({dist[x.second],x.second});
				parent[x.second] = u;		
			}
		}
	}
	

}

void getPath(LI *par,LI u)
{

	if(par[u]!=0)
		getPath(par,par[u]);
	
		cout << u << " ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI N,M;
	cin >> N >> M;
	
	VEC(PAIR(LI,LI)) graph[N+1];
	LI x,y,w;
	for(LI i=0; i<M; i++)
	{
		cin >> x >> y >> w;
		graph[x].push_back({w,y});
		graph[y].push_back({w,x});
	}

	LI parent[N+1]={0};

	dks(graph,1,N,parent);
	if(parent[N]!=0)
	{
		getPath(parent, N);
	}
	else
		cout << "-1";
	return 0;
}


