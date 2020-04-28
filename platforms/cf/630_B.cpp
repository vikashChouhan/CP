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
	int p[11] = {2,3,5,7,11,13,17,19,23,29,31};
	while(t--) 
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		int c[n]={0},m=0;
		for(int i=0; i<11; i++)
		{
			bool done=false;
			for(int j=0; j<n; j++)
			{
				if(!c[j] && arr[j]%p[i]==0)
				{
					c[j] = m+1;
					done=true;
				}
			}
			if(done) m++;
		}
		
		cout << m << "\n";
		for(int i=0; i<n; i++) cout << c[i] << " ";
		cout << "\n";
	}

	return 0;
}


