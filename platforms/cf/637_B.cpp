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

	int T;
	cin >> T;
	while(t--) 
	{
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++) cin >> arr[i];
		
		int temp[n]={0};
		for(int i=1; i<n-1; i++)
			if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
				temp[i] = 1;
		
		int l=0,cnt=0,maxcnt=0;
		for(int i=0; i<k-1; i++) cnt+=temp[i];
		maxcnt=cnt;
		for(int i=k-1; i<n-1; i++)
			if(maxcnt < cnt + temp[i] - temp[i-k+2])
			{
				maxcnt = cnt = cnt + temp[i] - temp[i-k+2];
				l = i-k+2;
			}
			else
				cnt += temp[i] - temp[i-k+2];
		cout << maxcnt+1 << " " << l+1 << "\n";
	}

	return 0;
}


