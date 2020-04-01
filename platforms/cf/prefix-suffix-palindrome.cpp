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

string getpalin(string s) {
	for(int j=s.length()-1; j>=0; j--) {
		if(s[0]==s[j]) {
			int f=1,l=j-1;
			while(f<l && s[f]==s[l]) {
				f++;l--;
			}
			if(s[f]==s[l])
				return s.substr(0,j+1);
		}
	}
	return s.substr(0,1);
}
string rev(string s) {
	string t;
	for(int i=s.length()-1; i>=0; i--)
		t+=s[i];
	return t;
}
int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if(s.length()==1) {
			cout << s << "\n";
			continue;
		}
		int f=0,l=s.length()-1;
		while(f<l && s[f]==s[l]) {
			f++;l--;
		}
		string a = s.substr(0,f);
		string b = s.substr(l+1);
//		cout << "f="<<f<<" l="<<l<<endl;
		string ls = getpalin(s.substr(f));
		string temp = rev(s.substr(0,l+1));
//		cout << "temp="<<temp<<endl;
		string rs = rev(getpalin(temp));
		
		
//		cout << "a="<<a<<endl;
//		cout << "b="<<b<<endl;
//		cout << "ls=" << ls<<endl;
//		cout << "rs="<<rs<<endl;
		if(s[f]==s[l])
			cout << a+b << "\n";
		else if(ls.length()>=rs.length())
			cout << a+ls+b << "\n";
		else
			cout << a+rs+b << "\n";
	}

	return 0;
}


