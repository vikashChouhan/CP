#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define LL long long
#define VEC(T) vector<T>
#define PAIR(T_,T__) pair<T_,T__>
#define MOD 1000000009

template <typename T>
void SWAP(T &_a, T &_b){ T t = _a;_a = _b; _b = t;}

template <typename T>
ostream &operator<<(ostream &stream, const vector<T>& inp_)
{ for(auto &x: inp_)stream << x << " "; stream << "\n";
return stream;}

template <typename T>
ostream &operator<<(ostream &stream, const set<T>& inp_)
{ for(auto &x: inp_)stream << x << " "; stream << "\n";
return stream;}

template <typename T,typename T_>
ostream &operator<<(ostream &stream, const pair<T,T_>& inp_)
{stream << "(" << inp_.first << "," << inp_.second <<") ";
return stream;}

int price[] = {100, 75, 50, 25};
map<int,int> mtime; 
map<int,int> rmtime; 
	
LI solve(auto &arr, int i, set<PAIR(char,int)> &ss, set<char> &sm, set<int>&st, int temp[][4])
{
	if(ss.size()==4 || i>=arr.size())
	{
		LI p = 0;
		int j = 0;
		VEC(int) tt;
		for(auto &x: ss)
			tt.push_back(temp[x.first-'A'][mtime[x.second]]);
			
		sort(tt.begin(),tt.end(),greater<int>());
		
		for(auto &x: tt)
			p+=x*price[j++];
		
		p -= (4-ss.size())*100;
		
		if(p==575)
			cout<<ss;
		return p;
	}
	
	LI profit = INT_MIN;
	for(int j = i; j<arr.size(); j++)
	{
		char mov = arr[j].second.first;
		int time = arr[j].second.second;
		
		if(sm.find(mov)==sm.end() && st.find(time)==st.end())
		{
			ss.insert(arr[j].second);
			sm.insert(mov);
			st.insert(time);
			
			profit = max(profit,solve(arr,j+1,ss,sm,st,temp));
			ss.erase(arr[j].second);
			sm.erase(mov);
			st.erase(time);
		}
		else
			profit = max(profit,solve(arr,j+1,ss,sm,st,temp));
	}
	
	return profit;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int T;
	cin >> T;
	

	LI totProfit = 0;
	mtime[12]=0;mtime[3]=1; mtime[6]=2; mtime[9]=3;
	rmtime[0]=12; rmtime[1]=3; rmtime[2]=6; rmtime[3]=9;

	while(T--)
	{
		int N;
		cin >> N;
		
		if(N==0)
		{
			totProfit += -400;
			cout << -400 <<"\n";
			continue;
		}
		char mov;
		int time;
		
		VEC(PAIR(int, PAIR(char,int))) arr;
		int temp[4][4]={0};
		
		for(int i = 0; i<N; i++)
		{
			cin >> mov >> time;
			temp[mov-'A'][mtime[time]]+=1;
		}
		
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				if(temp[i][j])
					arr.push_back({temp[i][j],{'A'+i,rmtime[j]}});
			}
		}
		
	
		sort(arr.begin(), arr.end(), greater<PAIR(int, PAIR(char,int))>());
	
		set<PAIR(char,int)> ss;
		set<char> sm;
		set<int> st;
		LI p = solve(arr,0,ss,sm,st,temp);
		cout << p <<"\n";
		totProfit += p;
	}
	
	cout << totProfit <<"\n";

	return 0;
}


