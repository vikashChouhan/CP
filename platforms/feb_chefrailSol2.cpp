#include<bits/stdc++.h>
using namespace std;

#define LI double
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


LI process(set<LI> &sp, set<LI> &sn, set<LI> &dp, set<LI> &dn, char src)
{
	LI res = 0;
	double temp;
	for(auto &ssn: sn)
	{
		for(auto &ssp: sp)
		{
			temp = sqrt(ssn*ssp*1.0);
			//cout << "temp = " << temp << " ";
			//cout << ssn << " " << ssp << endl;
			if(dp.find(temp)!=dp.end())
				res++;
			if(dn.find(temp)!=dn.end())	
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
				xneg.insert(-cinvar);
			else if(cinvar > 0)
				xpos.insert(cinvar);
			else
				xzero = true;
		}
		
		for(LI i=0; i<ny; i++)
		{
			cin >> cinvar;
			if(cinvar < 0)
				yneg.insert(-cinvar);
			else if(cinvar > 0)
				ypos.insert(cinvar);
			else
				yzero = true;
		}
		
		LI res = 0;
		res += process(xpos,xneg,ypos,yneg,'x');
		res += process(ypos,yneg,xpos,xneg,'y');
		
		if(xzero || yzero)
		{
			res += (xneg.size() + xpos.size())*(ypos.size() + yneg.size());
			
		}
		cout << res << "\n";
		
		
	}

	return 0;
}


