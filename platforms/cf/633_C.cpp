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

	LI t; cin >> t;
	while(t--)
	{
		LI N;
		cin >> N;
		LI arr[N];
		for(LI i=0; i<N; i++) cin >> arr[i];
		
		LI ans = 0;
		LI mx = arr[0];
		for(LI i=1; i<N; i++)
		{
			if(arr[i]<mx)
			{
				ans = max(ans, long(log2(mx-arr[i]))+1);
			}
			else
				mx = arr[i];
		}
		cout << ans << "\n";
	}

	return 0;
}


