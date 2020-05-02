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
		sort(s.begin(), s.end());
		if(k==1) cout << s <<"\n";
		else
		{
			if(s[0]!=s[k-1])
				cout << s[k-1] << "\n";
			else if(s[k]==s[n-1])
			{
				cout << s[0];
				for(int i=0; i<(n-1)/k; i++)
					cout << s[k];
				cout << "\n";
			}
			else
				cout << s[0] << s.substr(k) <<"\n";
			
		}
	}

	return 0;
}


