#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define ULL unsigned long long
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

ULL bit[1000005];
LI N;
void update(LI i, ULL val)
{
	while(i<=N)
	{
		bit[i]+= val;
		i+=i&(-i);
	}
}

ULL query(LI i)
{
	ULL sum = 0;
	while(i>0)
	{
		sum+=bit[i];
		i-=i&(-i);
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI m,c;
	cin >> N >> m >> c;
	
	while(m--)
	{
		char t;
		cin >> t;
		LI u,v,k,p;
		if(t=='S')
		{
			cin >> u >> v >> k;
			update(u,k);
			update(v+1,-k);
			
		}
		else
		{
			cin >> p;
			cout << query(p) + c <<"\n";
		}
	}
	return 0;
}


