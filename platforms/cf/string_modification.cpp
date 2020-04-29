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

inline void reverse(string &s, int i, int j)
{
	while(i<j)
	{
		SWAP(s[i],s[j]);
		i++;j--;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		int bestk = 1;
		string minlex=s;
		string temp;
		for(int k=2; k<=n; k++)
		{
			temp = s;
			if((n-k+1)%2==1)
				reverse(temp,0,k-2);
			temp = temp.substr(k-1) + temp.substr(0,k-1);
			if(minlex > temp)
			{
				minlex = temp;
				bestk = k;
			}
		}
		cout << minlex << "\n";
		cout << bestk <<"\n";
	}

	return 0;
}


