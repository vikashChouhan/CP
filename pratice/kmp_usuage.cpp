#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000009

template <typename T>
ostream &operator<<(ostream &stream, const vector<T>& inp_)
{ for(auto &x: inp_)stream << x << " "; stream << "\n";
return stream;}

template <typename T,typename T_>
ostream &operator<<(ostream &stream, const pair<T,T_>& inp_)
{stream << "(" << inp_.first << "," << inp_.second <<") ";
return stream;}


template <typename T>
void SWAP(T &_a, T &_b){ T t = _a;_a = _b; _b = t;}



void update_lps(vector<LI> &lps, const string &p)
{
	lps[0] = 0;
	for(LI i = 1; i < p.length(); i++)
	{
		LI j = i-1;
		while(j>0 && p[i] != p[j])
		{
			j = lps[j];
		}
		if(p[j] == p[i])
			lps[i] = lps[j]+1;
		else
			lps[i] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI N;
	cin >> N;
	
	string ptn;
	cin >> ptn;
	
	vector<LI> lps(N);
	update_lps(lps,ptn);
	
	
	char ch='.';
	LI loc = 0;
	LI j = 0;
	while(1)
	{
		ch = getchar();
		if(ch=='\n')
			break;
		loc++;
		if(ch == ptn[j])
			j++;
		else
		{
			if(j > 0)
				j = lps[j-1];
		}
		if(j == ptn.length())
		{
			cout << loc-ptn.length() <<"\n";
			j = lps[j-1];
		}
	}
	cout << "\n";

	return 0;
}


