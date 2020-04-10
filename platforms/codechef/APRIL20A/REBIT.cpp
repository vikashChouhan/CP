#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL unsigned long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 998244353
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

LL eE(LL a, LL b, LL &x, LL &y)
{
	if(b==0)
	{
		x = 1; y = 0;
		return a;
	}
	
	LL x1, y1;
	LL gcd = eE(b,a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	
	return gcd;
}
LL modInv(LL a, LL m)
{
	LL x,y;
	LL gcd = eE(m,a,x,y);
	return (y%m + m)%m;
}
struct node
{
	char ch='.';
	VEC(LL) vec;
	
	node(char val,VEC(LL) v={748683265,748683265,748683265,748683265})
	{
		ch = val;
		vec = v;
	}
};

VEC(LL) combine(VEC(LL) &l, VEC(LL) &r, char op)
{
	VEC(LL) res;
	if(op=='|')
	{
		res.push_back(((l[0]*r[0])%MOD)%MOD);
		res.push_back(((l[0]*r[1])%MOD + (l[1]*r[0])%MOD + (l[1]*r[1])%MOD + (l[1]*r[2])%MOD + (l[2]*r[1])%MOD + (l[1]*r[3])%MOD + (l[2]*r[3])%MOD + (l[3]*(r[1] + r[2]))%MOD)%MOD);
		res.push_back(((l[0]*r[2])%MOD + (l[2]*r[0])%MOD + (l[2]*r[2])%MOD)%MOD);
		res.push_back(((l[0]*r[3])%MOD + (l[3]*r[3])%MOD + (l[3]*r[0])%MOD)%MOD);
	}
	else if(op=='&')
	{
		res.push_back(((l[0]*(r[0]+r[1]+r[2]+r[3])%MOD)%MOD + (l[1]*r[0])%MOD + (l[2]*(r[0]+r[3]))%MOD + (l[3]*(r[0]+r[2]))%MOD)%MOD);
		res.push_back((l[1]*r[1])%MOD);
		res.push_back(((l[1]*r[2])%MOD + (l[2]*(r[1]+r[2]))%MOD)%MOD);
		res.push_back(((l[1]*r[3])%MOD + (l[3]*r[3])%MOD + (l[3]*r[1])%MOD)%MOD);
	}
	else if(op=='^')
	{
		res.push_back(((l[0]*r[0])%MOD + (l[1]*r[1])%MOD + (l[2]*r[2])%MOD + (l[3]*r[3])%MOD)%MOD);
		res.push_back(((l[0]*r[1])%MOD + (l[1]*r[0])%MOD + (l[2]*r[3])%MOD + (l[3]*r[2])%MOD)%MOD);
		res.push_back(((l[0]*r[2])%MOD + (l[2]*r[0])%MOD + (l[1]*r[3])%MOD + (l[3]*r[1])%MOD)%MOD);
		res.push_back(((l[1]*r[2])%MOD + (l[2]*r[1])%MOD + (l[0]*r[3])%MOD + (l[3]*r[0])%MOD)%MOD);
	}
	return res;
}



VEC(LL) solve(string str)
{
	stack<node*> stk;
	for(LI i=0; i<str.length(); i++)
	{
		if(str[i]!=')') stk.push(new node(str[i]));
		else
		{
			node* r = stk.top(); stk.pop();
			node* op = stk.top(); stk.pop();
			node* l  = stk.top(); stk.pop();
			stk.pop();
			
			VEC(LL) res;
			if(r->ch=='#' && l->ch=='#')
			{
				if(op->ch=='|') res = {935854081,436731905,811073537,811073537};
				else if(op->ch=='&') res={436731905,935854081,811073537,811073537};
				else
					res = {748683265,748683265,748683265,748683265};
			}
			else
				res = combine(l->vec,r->vec,op->ch);
			
			stk.push(new node('.',res));
		}
	}
	
	return stk.top()->vec;	
		
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
	
		VEC(LL) v;
		if(str.length()==1) 
			v = {748683265,748683265,748683265,748683265};
		else
			v = solve(str);
		
		
		cout << v[0]%MOD << " " << v[1]%MOD << " " << v[2]%MOD <<" " << v[3]%MOD<< "\n";
	}

	return 0;
}


