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

typedef PAIR(LI,PAIR(LI,LI)) ppp;
	
bool comp(const ppp &a, const ppp &b)
{
	if(a.first < b.first) return true;
	else if(a.first > b.first) return false;
	else
	{
		if(a.second.first > b.second.first) return true;
		else
			return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	
	while(t--)
	{
		LI N, Days;
		cin >> N >> Days;
		
		priority_queue<ppp> Q;
		VEC(ppp) p;
		LI D,T,S;
		for(LI i=0; i<N; i++)
		{
			cin >> D >> T >> S;
			
			p.push_back({D,{S,T}});
		}
		
		sort(p.begin(),p.end(),comp);
		
		LI currday = p[0].first;
		for(LI i=0; i<N; i++)
		{
			if(p[i].first <= currday)
			{
				if((Q.empty() || Q.top().first < p[i].second.first))
				{
					p[i].second.second--;
					if(p[i].second.second)
						Q.push({p[i].second.first,{p[i].first,p[i].second.second}});
				}
				else
				{
					ppp temp = Q.top();
					Q.pop();
					temp.second.second--;
					if(temp.second.second)
						Q.push(temp);
					
					Q.push({p[i].second.first,{p[i].first,p[i].second.second}});
				}
					
			}
			else if(!Q.empty())
			{
					ppp temp = Q.top();
					Q.pop();
					temp.second.second--;
					if(temp.second.second)
						Q.push(temp);	
			}
			else
			{
				currday = p[i].first-1;
				i--;
			}
			currday++;
			if(currday>Days)
				break;
		}
		
		LI ans = 0;
		while(!Q.empty() && currday<=Days)
		{
			ppp temp = Q.top();
			Q.pop();
			S = temp.first;
			D = temp.second.first;
			T = temp.second.second;
			
			if(currday+T-1<=Days)
			{
				currday+=T;
			}
			else
			{
				ans = (currday+T-1-Days)*S;
				break;
			}
		}
		
		while(!Q.empty())
		{
			ans += Q.top().first*Q.top().second.second;
			Q.pop();
		}
		
		cout << ans << "\n";
	}

	return 0;
}


