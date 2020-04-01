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

VEC(PAIR(int,int)) path,anspath;
int board[9][9] = {0};
set<PAIR(int,int)> vis;
int ans = INT_MAX;

inline bool valid(int r,int c)
{
	return (r<=8 && r>=1) && (c<=8 && c>=1);
}

void countpath(int,int);
void ite(int r, int c, int rs, int cs)
{
	
	for(int i=1; i<=8; i++)
	{
		if(valid(r+rs*i,c+cs*i) && !board[r+rs*i][c+cs*i])
		{
			board[r+rs*i][c+cs*i] = 1;
			path.push_back({r+rs*i,c+cs*i});
			for(int j=1; j<=i; j++)
				vis.insert({r+rs*j,c+cs*j});
		
			countpath(r+rs*i,c+cs*i);
			
			if(vis.size()==32)
			{
				board[r+rs*i][c+cs*i] = 0;
				path.pop_back();
				for(int j=1; j<=i; j++)
					vis.erase({r+rs*j,c+cs*j});		
			}
			else
				path.push_back({r,c});
		}
	}
}
void countpath(int r,int c)
{
	if(path.size() > 64) return;
	if(vis.size()==32)
	{			
		if(path.size()<ans)
		{
			ans = path.size();
			anspath = path;
		}
		return;
	}
	
	ite(r,c,1,1);
	ite(r,c,1,-1);
	ite(r,c,-1,1);
	ite(r,c,-1,-1);
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	
	while(t--)
	{
		int r,c;
		cin >> r >> c;
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++)
				board[i][j] = 0;
		
		int temp = c;
		c = r;
		r = 8-temp+1;
		
		board[r][c] = 1;
		path.clear();
		ans = INT_MAX;
		vis.clear();
		path.push_back({r,c});
		vis.insert({r,c});
		
		countpath(r,c);
		cout << anspath.size() << "\n";
		for(int i=0; i<anspath.size(); i++)
		{
			cout << anspath[i].second << " " << 8 - anspath[i].first + 1 << "\n";
		}
	}

	return 0;
}


