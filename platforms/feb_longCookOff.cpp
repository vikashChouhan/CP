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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	LI T;
	cin >> T;
	
	while(T--)
	{
		LI m1, y1, m2, y2;
		cin >> m1 >> y1 >> m2 >> y2;
		
		VEC(int) tar(28);
		double temp;
		LI res = 0;
		for(LI y = y1; y<=min(y2,y1+27); y++)
		{
			if(y==y1 && m1>2) continue;
			if(y==y2 && m2<2) continue;
			temp = ((y-1) + (y-1)/4 + (y-1)/400 - (y-1)/100 + 3 + 1);
			if(long(temp)%7==6)
				tar[y-y1] = 1;
			
			if(long(temp)%7==0 && !(y%400==0 || (y%4==0 && y%100)))
				tar[y-y1] = 1;
			
			res+=tar[y-y1];
		}
		
		
		if(y2-y1 > 27)
		{
			res = res*((y2-y1)/27);
			if((y2-y1)%27)
				for(LI i=0; i<(y2-y1)%27; i++)
					res+=tar[i];
		}
		
		cout << res <<"\n";
	}

	return 0;
}


