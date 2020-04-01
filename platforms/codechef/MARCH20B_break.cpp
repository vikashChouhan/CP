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
	//cin.tie(NULL);cout.tie(NULL);

	LI T, S;
	cin >> T >> S;
	while(T--)
	{
		LI N;
		cin >> N;
		LI a[N],b[N];
		unordered_map<LI,LI>mma;
		map<LI,LI> mmb;
		LI mina = INT_MAX;
		for(LI i=0; i<N; i++)
		{
			cin >> a[i];
			mma[a[i]]++;
			mina = min(mina,a[i]);
		}
		for(LI i=0; i<N; i++)
		{
			cin >> b[i];
			mmb[b[i]]++;
		}
		
		if(S==1)
		{
			unordered_map<LI,LI>ontable;
			bool draw = true;
			LI chn = mina,fn;
			
			while(mma.size() && mmb.size())
			{
				auto it = mmb.upper_bound(chn);
				if(it->second==0) {
					draw = false;
					break;
				}
				
				ontable[it->first] = 1;
				ontable[chn] = 1;
				
				mmb[it->first]--;
				if(mmb[it->first]==0)
					mmb.erase(it->first);
				
				mma[chn]--;
				//cout << chn << " " << mma[chn]; 
				if(mma[chn]==0)
					mma.erase(chn);
				
				//cout << " " << mma.size() << endl;
				bool hascard=false;
				if(mma.size()==0) break;
				for(auto x: ontable) {
					if(mma.find(x.first)!=mma.end())
					{
						chn = x.first;
						hascard = true;
						break;
					}
				}
				
				if(!hascard) {
					draw = false;
					break;
				}
			}
			
			//cout << draw <<" "<<mma.size() << " "<< mmb.size() << "\n";
			if(draw && mma.size()==0 && mmb.size()==0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			cout << 2 << "\n";
	}

	return 0;
}


