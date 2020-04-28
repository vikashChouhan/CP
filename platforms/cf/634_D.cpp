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

inline void increase(char &ch)
{
	if(ch=='9') ch='1';
	else
		ch+=1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		string s[9];
		for(int i=0; i<9; i++) cin >> s[i];
		increase(s[0][0]);
		increase(s[1][3]);
		increase(s[2][6]);
		increase(s[3][1]);
		increase(s[4][4]);
		increase(s[5][7]);
		increase(s[6][2]);
		increase(s[7][5]);
		increase(s[8][8]);
		for(int i=0; i<9; i++) cout << s[i] <<"\n";
	}

	return 0;
}


