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


inline void getpalin(string &s, int start, int end, string &res)
{
	vector<int>d1(end-start+1),d2(end-start+1);
	int n = end-start+1;
	for(int i=0, l=0, r=-1; i<n; i++)
	{
		int k = (i>r)?1: min(d1[l+r-i], r-i+1);
		while(0<=i-k && i+k<n && s[i-k + start]==s[i+k + start])
			k++;
		d1[i] = k--;
		if(i+k>r)
		{
			l=i-k;
			r = i+k;
		}
	}
	for(int i=0, l=0, r=-1; i<n; i++)
	{
		int k = (i>r)?0: min(d2[l+r-i-1], r-i+1);
		while(0<=i-k-1 && i+k<n && s[i-k-1 + start]==s[i+k + start])
			k++;
		d2[i]=k--;
		if(i+k>r)
		{
			l = i-k-1;
			r = i+k;
		}
	}
//	cout << d1 << d2;
	
	int len1=0,len2=0;
	for(int i=1; i<=end-start+1; i++)
	{
		if(d1[i-1]==i)
			len1 = max(len1,2*d1[i-1]-1);
		if(d2[i-1]==i)
			len1 = max(len1,2*d2[i-1]);
		
		if(d1[i-1]-1==n-i)
			len2 = max(len2,2*d1[i-1]-1);
		if(d2[i-1]-1==n-i)
			len2 = max(len2,2*d2[i-1]);
	}
//	cout << len1 << " , " << len2<<endl;
	if(len1 > len2)
		res = s.substr(start, len1);
	else
		res = s.substr(end-len2+1,len2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		
		string a, b;
		int i=0, j=s.length()-1;
		while(s[i]==s[j] && i<=j)
		{
			i++; j--;
		}
		if(i>j)
			cout << s << "\n";
		else
		{
			a = s.substr(0,i);
			b = s.substr(j+1);
			
//			cout << a << "->" << b <<"\n";
			string c;
			getpalin(s, i, j, c);
//			cout << c << "\n";
			
			cout << a + c + b <<"\n";
		}
		
	}

	return 0;
}


