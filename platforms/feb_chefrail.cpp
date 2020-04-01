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
ostream &operator<<(ostream &stream, const set<T>& inp_)
{ for(auto &x: inp_)stream << x << " "; stream << "\n";
return stream;}

template <typename T>
T GCD(T a, T b) 
{T temp;while(b>0){temp = b;b = a%b;a = temp;}
return a;}

#define PI 3.14159265 

inline PAIR(PAIR(char,LI),PAIR(LI,LI)) INV(PAIR(PAIR(char,LI),PAIR(LI,LI)) &t)
{
	PAIR(PAIR(char,LI),PAIR(LI,LI)) res;
	if(t.first.first == '-')
		res.first.first = '+';
	else
		res.first.first = '-';
	
	res.first.second = t.first.second;
	res.second.first = t.second.second;
	res.second.second = t.second.first;
	
	return res;
}

LI process(set<LI> &s, set<LI> &p, set<LI> &n, char src)
{
	if(p.size()==0 || n.size()==0 || s.size()==0)
		return 0;
	
	set<PAIR(PAIR(char,LI),PAIR(LI,LI))> pslope;
	LI gcd;
	
	for(auto &ss: s)
	{
		for(auto &dd: p)
		{
			gcd = GCD(max(abs(dd),abs(ss)),min(abs(dd),abs(ss)));	
			if(src=='y')
			{
				if(ss<0)
					pslope.insert({{'+',ss},{-ss/gcd,dd/gcd}});
				else
					pslope.insert({{'-',ss},{ss/gcd,dd/gcd}});
			}
			else
			{
				if(ss<0)
					pslope.insert({{'+',ss},{dd/gcd,-ss/gcd}});
				else
					pslope.insert({{'-',ss},{dd/gcd,ss/gcd}});
			}
		}
		
	}
	//cout << pslope;
	LI res = 0;
	double ang;
	PAIR(PAIR(char,LI),PAIR(LI,LI)) temp;
	for(auto &ss: s)
	{
		for(auto &dd: n)
		{
		
				
			gcd = GCD(max(abs(dd),abs(ss)),min(abs(dd),abs(ss)));	
			if(src=='y')
			{
				if(ss<0)
					temp = {{'-',ss},{-ss/gcd,-dd/gcd}};
				else
					temp = {{'+',ss},{ss/gcd,-dd/gcd}};
			}
			else
			{
				if(ss<0)
					temp = {{'-',ss},{-dd/gcd,-ss/gcd}};
				else
					temp = {{'+',ss},{-dd/gcd,ss/gcd}};
			}
			//cout << temp << " " << INV(temp);
			if(pslope.find(INV(temp))!=pslope.end())
				res++;
		}
	}
	
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	LI T;
	cin >> T;
	
	while(T--)
	{
		LI nx, ny;
		cin >> nx >> ny;
		
		set<LI> xneg,xpos,yneg,ypos;
		
		LI cinvar;
		bool xzero = false,yzero=false;
		for(LI i=0; i<nx; i++)
		{
			cin >> cinvar;
			if(cinvar < 0)
				xneg.insert(cinvar);
			else if(cinvar > 0)
				xpos.insert(cinvar);
			else
				xzero = true;
		}
		
		for(LI i=0; i<ny; i++)
		{
			cin >> cinvar;
			if(cinvar < 0)
				yneg.insert(cinvar);
			else if(cinvar > 0)
				ypos.insert(cinvar);
			else
				yzero = true;
		}
		
		LI res = 0;
		res += process(xneg,ypos,yneg,'x');
		res += process(xpos,ypos,yneg,'x');
		res += process(yneg,xpos,xneg,'y');
		res += process(ypos,xpos,xneg,'y');
		
		if(xzero || yzero)
		{
			res += (xneg.size() + xpos.size())*(ypos.size() + yneg.size());
			
		}
		cout << res << "\n";
		
		
	}

	return 0;
}


