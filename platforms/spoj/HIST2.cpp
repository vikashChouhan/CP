#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000007

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

	int N;
	cin >> N;
	int a[20];
	while(N!=0)
	{
		
		for(int i=0; i<N; i++)
			cin >> a[i];
			
		VEC(int) per;
	
		while(next_permutation(a,a+N))
		{
			int p = 2*N + a[0] + a[N-1];
			for(int i=1; i<N; i++)
			{
				p+=abs(a[i]-a[i-1]);
			}
			
			per.push_back(p);
		}
		
		
		int m = *max_element(per.begin(),per.end());
		int cnt = count(per.begin(),per.end(),m);
		
		cout << m << " " << cnt << "\n";
		
		cin >> N;
	}

	return 0;
}


