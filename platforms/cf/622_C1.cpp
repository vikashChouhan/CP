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

	int n; cin >> n;
	vector<LL>arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	vector<LL>ans, temp;
	LL mm=INT_MIN;
	for(int i=0; i<n; i++)
	{
		temp = arr;
		LL sum=temp[i];
		for(int j=i+1; j<n; j++)
		{
			temp[j] = min(temp[j-1],temp[j]);
			sum+=temp[j];
		}
		for(int j=i-1;j>=0;j--)
		{
			temp[j] = min(temp[j],temp[j+1]);
			sum+=temp[j];
		}
		if(mm<sum)
		{
			mm = sum;
			ans = temp;
		}
	}
	
	for(LL x: ans) cout << x << " ";
	return 0;
}


