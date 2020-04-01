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
	
	int t;
	cin >> t;
	while(t--)
	{
		int N, M;
		cin >> N >> M;
		int f[N],p[N];
		
		for(int i=0; i<N; i++)
			cin >> f[i];
		for(int i=0; i<N; i++)
			cin >> p[i];
		
		int ans = INT_MAX;
		unordered_map<int,int>sum;
		for(int i=0; i<N; i++)
			sum[f[i]] += p[i];
		
		for(auto it=sum.begin(); it!=sum.end(); it++)
			ans=min(ans,it->second);
		
		cout << ans << "\n";
	}


	return 0;
}


