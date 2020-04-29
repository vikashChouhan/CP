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
	while(t--)
	{
		int n; cin >> n;
		LL arr[n],minele=INT_MAX,maxele=INT_MIN;
		for(int i=0; i<n; i++) 
			cin >> arr[i];
		
		for(int i=0; i<n; i++)
		{
			if(arr[i]==-1)
			{
				if(i!=0 && arr[i-1]!=-1)
				{
					minele = min(minele, arr[i-1]);
					maxele = max(maxele, arr[i-1]);
				}
				
				if(i!=n-1 && arr[i+1]!=-1)
				{
					minele = min(minele,arr[i+1]);
					maxele = max(maxele, arr[i+1]);
				}
			}
		}
		
		if(minele == INT_MAX)
			cout << "0 0\n";
		else
		{
			LL k = (minele+maxele)/2, m = INT_MIN;
			for(int i=0; i<n; i++)
				if(arr[i]==-1) 
					arr[i] = k;
			
			for(int i=0; i<n-1; i++)
				m = max(m, abs(arr[i+1]-arr[i]));
			
			cout << m << " " << k <<"\n";
		}
	}

	return 0;
}


