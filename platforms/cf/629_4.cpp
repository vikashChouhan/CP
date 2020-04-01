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

	LI q;
	cin >> q;
	while(q--) {
		LI n; cin >> n;
		LI arr[n];
		LI k=0;
		unordered_map<LI,LI>t;
		for(LI i=0; i<n; i++) {
			cin >> arr[i];
		}
		
		t[arr[0]] = 1;
		k = 1;
 		for(LI i=1; i<n; i++) {
			if(i!=n-1 && arr[i]!=arr[i-1]) {
				bool done=false;
				for(auto x:t) {
					if(x.first!=arr[i-1]) {
						done = true;
						t[arr[i]] = x.second;
						break;
					}
				}
				
				if(!done) {
					k++;
					t[arr[i]] = k;
				}
			}
			else if(i!=n-1 && arr[i]==arr[i-1] ) {
				t[arr[i]] = t[arr[i-1]];
			}
		}
		
		if(arr[n-1]!=arr[n-2] && arr[n-1]!=arr[0]) {
			bool done =false;
			for(auto x:t) {
				if(x.first!=arr[n-2] && x.first!=arr[0]) {
					done = true;
					t[arr[n-1]]=x.second;
					break;
				}
			}
			if(!done) {
				k++;
				t[arr[n-1]] = k;
			}
		}
		else if(arr[n-1]==arr[n-2]) t[arr[n-1]] = t[arr[n-2]];
		else 
			t[arr[n-1]] = t[arr[0]];
		
		cout << k << "\n";
		for(LI i=0; i<n; i++) cout << t[arr[i]] << " ";
		cout << "\n";
	
	}

	return 0;
}


