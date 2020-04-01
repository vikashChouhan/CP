#include<bits/stdc++.h>
using namespace std;

#define LI long long
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

VEC(LI) pp(int *arr,LI n)
{
	VEC(LI) res(n+1,0);
	for(LI i=1; i<=n; i++)
	{
		if(arr[i]==0) continue;
		
		LI j = i;
		while(j<=n && arr[j]!=0) j++;
		for(LI len=1; len<=j-i; len++)
			res[len] += j-i-len+1;
		i=j-1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI n,m,k;
	cin >> n >> m >> k;
	int a[n+1]={0},b[m+1]={0};
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=m; i++) {
		cin >> b[i];
	}
	
	VEC(LI) sa = pp(a,n);
	VEC(LI) sb = pp(b,m);
	LI ans = 0;
	for(LI x =1; x<sa.size(); x++) {
		if(k%x==0 && k/x<=m)
			ans += sa[x]*sb[k/x];
	}
	cout << ans;
	return 0;
}


