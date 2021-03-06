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
	
	int n; cin >> n;
	long long b[n], temp[n];
	for(int i=0; i<n; i++) 
	{
		cin >> b[i];
		temp[i]	 = b[i]-i-1;
	}
	
	unordered_map<int,vector<long long>> mm;
	for(int i=0; i<n; i++)
	{
		mm[temp[i]].emplace_back(b[i]);
	}
	
	unsigned long long ans = 0;
	for(auto &x: mm)
	{
		unsigned long long sum = 0;
		sum = accumulate(x.second.begin(),x.second.end(), sum);
		ans = max(sum, ans);
	}
	cout << ans;

	return 0;
}


