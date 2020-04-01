#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007
#define INF 1000000000000000000ll

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

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		
		int per[k][n]={0};
		for(int i=0; i<k; i++)
			for(int j=0; j<n; j++)
			{
				cin >> per[i][j];
			}
		
		unordered_set<int> graph[n+1],graphR[n+1];
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(i!=j)
					graph[i].insert(j);
		
		for(int i=0; i<k; i++)
			for(int j=0; j<n; j++)
				for(int x=0; x<j; x++)
					graph[per[i][j]].erase(per[i][x]);
		
		for(int i=1; i<=n; i++)
		{
			for(auto x:graph[i])
				graphR[x].insert(i);
		}
		
		int temp,ele=-1;
		for(int i=1; i<=n; i++)
		{
			if(graph[i].empty()) continue;
			
			temp = 5001;
			ele = -1;
			for(auto x: graph[i])
			{
				if(temp > graphR[x].size())
				{
					temp = graphR[x].size();
					ele = x;
				}
			}
			
			for(auto x:graphR[ele])
				if(x!=i)
					graph[x].erase(ele);
			
			for(auto x:graph[i])
				if(x!=ele)
					graphR[x].erase(i);
			
			graph[i].clear();
			graphR[ele].clear();
			graph[i].insert(ele);
			graphR[ele].insert(i);
		}
		
		int indeg = 0;
		for(int i=1; i<=n; i++)
			indeg += graphR[i].size()==0;
		
		cout << indeg << "\n";
		for(int i=1; i<=n; i++)
			if(graph[i].size())
				cout << *graph[i].begin() << " ";
			else
				cout << 0 << " ";
		
		cout << "\n";
	}
	return 0;
}


