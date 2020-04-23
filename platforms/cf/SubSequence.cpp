#include<bits/stdc++.h>
using namespace std;

#define LI unsigned long int
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

LL N,K;
LL dp[16][100005];

void update(LI k,LI val, LI i)
{
	while(i<=N)
	{
		dp[k][i]+=val;
		i+=i&(-i);
	}
}
LL query(LI k, LI i)
{
	LL sum = 0;
	while(i>0)
	{
		sum += dp[k][i];
		i-=i&(-i);
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N >> K; 
	K++;
	LI arr[N];
	for(LL i=0; i<N; i++)
	{
		cin >> arr[i];
		update(1,1,arr[i]);
		for(LI j=2; j<=K; j++)
			update(j,query(j-1,arr[i]-1),arr[i]);
	}
	cout << query(K,N);
	return 0;
}


