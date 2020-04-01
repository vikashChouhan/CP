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

int mat[2501][2501];
int matH[2501][2501];
int matV[2501][2501];

LI findSqrR(int i, int j, int N)
{
	LI res = 0;
	res++;
	
	bool hok=false,vok=false;
	for(int size = 2; size<=N; size++)
	{
		hok=vok=true;
		if(i+size>N || j+size>N)
			break;
		
		for(int x=i; x<i+size && hok; x++)
			if(i==0)
				hok = matH[x][j+size-1]==1;
			else
				hok = (matH[x][j+size-1]-mat[x][j-1])==1;
		
		if(hok)
		{
			for(int x=j; x<j+size && vok; x++)
				if(j==0)
					vok = matV[i+size-1][x]==1;
				else
					vok = (matV[i+size-1][x]-matV[i-1][x])==1;
		}
		
		if(hok && vok)
		{
			cout << i << " " << j << " " << size << endl;
			res++;
		}
	}
	
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);


	int t;
	cin >> t;
	while(t--)
	{
		int N;
		cin >> N;
		
		
		string s;
		for(int i=0; i<N; i++)
		{
			cin >> s;
			for(int j=0; j<s.length(); j++)
			{
				mat[i][j] = s[j]-'0';
				if(j==0)
					matH[i][j] = mat[i][j];
				else
					matH[i][j] = matH[i][j-1]+mat[i][j];
				
				if(i==0)
					matV[i][j] = mat[i][j];
				else
					matV[i][j] = matV[i-1][j]+mat[i][j];
			}
		}
			
		LI res = 0;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				if(mat[i][j])
				{
					res += findSqrR(i,j,N);
					//res += findSqrL(i,j,N);
				}
		}
		
		cout << res << "\n";
	}

	return 0;
}


