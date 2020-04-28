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
	cin.tie(NULL);cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		
		unordered_map<char,int> mm;
		char maxchar;
		int ans = 0;
		for(int i=0; i<k; i++)
		{
			int x = 0;
			maxchar = s[i];
			int maxcnt = -1;
			mm.clear();
			while(x<n/k)
			{
				mm[s[i + k*x]]++;
				if(mm[s[i + k*x]] > maxcnt)
				{
					maxcnt = mm[s[i + k*x]];
					maxchar = s[i + k*x];
				}
				
				mm[s[k-1-i + k*x]]++;
				if(mm[s[k-1-i + k*x]] > maxcnt)
				{
					maxcnt = mm[s[k-1-i + k*x]];
					maxchar = s[k-1-i + k*x];
				}
				x++;
			}
			
			for(auto ch: mm)
				if(ch.first!=maxchar)
					ans += ch.second;
		}	
		cout << ans/2 <<"\n";	
	}


	return 0;
}


