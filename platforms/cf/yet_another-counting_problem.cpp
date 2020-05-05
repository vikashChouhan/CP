#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL unsigned long long
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

LL a,b,q;

LL query(LL *temp, LL k)
{
	return (k/(a*b))*temp[a*b] + temp[k%(a*b)];
}
void solve()
{
	LL temp[a*b+1]={0};
	for(int i=1; i<=a*b; i++)
		temp[i] = temp[i-1] + ((i%a)%b!=(i%b)%a);
	
	while(q--)
	{
		LL l,r;
		cin >> l >> r;
		cout << query(temp,r)-query(temp,l-1) << " ";
	}
	cout <<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> q;
		solve();
	}

	return 0;
}


