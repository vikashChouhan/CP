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


bool canreach(VEC(LI) *graph,LI s,LI d,set<LI> &restpt,LI dist, LI k, int *vis)
{
	
	if(dist > k) return false;
	if(s==d)
		return true;
	vis[s] = 1;	
	if(restpt.find(s)!=restpt.end())
		dist = 0;
	for(auto &x: graph[s])
	{
		if(!vis[x])
		{
			if(restpt.find(x)!=restpt.end())
				vis[s] = 0;
				
			if(canreach(graph,x,d,restpt,dist+1,k,vis))
				return true;
		}
	}
	
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI n, k, r;
	cin >> n >> k >> r;
	
	VEC(LI) graph[n+1];
	for(LI i=0; i<n-1; i++)
	{
		LI x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	set<LI> restpt;
	for(LI i=0; i<r; i++)
	{
		LI x;
		cin >> x;
		restpt.insert(x);
	}

	LI v;
	cin >> v;
	int vis[n+1] = {0};
	for(LI i=0; i<v; i++)
	{
		LI s,d;
		cin >> s >> d;
		memset(vis,0,sizeof vis);
		if(canreach(graph,s,d,restpt,0,k,vis))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}


