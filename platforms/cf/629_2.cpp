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

string s;

void solve(LL n, LL k,  int cntb=2) {
	if(n==0) return;
	
	if(cntb==0){
		string temp(n,'a');
		s+=temp;
		return;
	}
//	cout << "n="<<n<<" b="<<cntb<<endl;
	LL starta = 0;
	if(cntb==2)
		starta = (n-1)*(n-2)/cntb;
	else
		starta = n-1;
	if(k<=starta)
	{
		s+='a';
		solve(n-1,k,cntb);
	}
	else
	{
//		cout << "y\n";
		s+='b';
		solve(n-1,k-starta,cntb-1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);cout.tie(NULL);

	LI t;
	cin >> t;
	while(t--) {
		LL n,k;
		cin >> n >> k;
		s = "";
		solve(n,k,2);
		cout << s << "\n";
	}

	return 0;
}


