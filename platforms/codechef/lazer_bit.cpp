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

struct node {
	LI pos=0,l=0,r=0,val=0;
};

bool comp(node &a, node &b)
{
	if(a.val == b.val) return a.l>b.l;
	return a.val > b.val;
}

void update(LI *bit, LI N, LI idx)
{
	while(idx<=N)
	{
		bit[idx]++;
		idx+=idx&(-idx);
	}
}

LI query(LI *bit, LI idx)
{
	LI ans = 0;
	while(idx)
	{
		ans += bit[idx];
		idx -= idx&(-idx);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		LI N,Q;
		cin >> N >> Q;
		
		LI size = N-1,i1=1;
		node arrmin[size+Q+1],arrmax[size+Q+1];
		LI x,prev;
		
		for(LI i=1; i<=N; i++)
		{
			cin >> x;
			if(i!=1)
			{
				arrmin[i1].val = min(x,prev);
				arrmin[i1].r = i1;
				
				arrmax[i1].val = -max(x,prev);
				arrmax[i1].r = i1;
				i1++;
			}
			prev = x;
		}
		
		LI x1,x2,y;
		LI xval[Q+1][2];
		for(LI i=size+1; i<=size+Q; i++)
		{
			cin >> x1 >> x2 >> y;
			xval[i-size][0] = x1;
			xval[i-size][1] = x2;
			
			arrmin[i].pos = i-size;
			arrmin[i].val = y;
			arrmin[i].l = x1;
			arrmin[i].r = x2-1;
			
			arrmax[i].pos = i-size;
			arrmax[i].val = -y;
			arrmax[i].l = x1;
			arrmax[i].r = x2-1;
		}
		
		sort(arrmin+1,arrmin+size+Q+1,comp);
		sort(arrmax+1,arrmax+size+Q+1,comp);
		
		LI ansmin[Q+1],ansmax[Q+1],bitmin[size+1]={0},bitmax[size+1]={0};
		LI cnt1,cnt2;
		for(LI i=1; i<=size+Q; i++)
		{
			if(arrmin[i].pos!=0)
			{
				cnt1 = query(bitmin,arrmin[i].r)-query(bitmin,arrmin[i].l-1);
				ansmin[arrmin[i].pos] = cnt1;
			}
			else
				update(bitmin,size,arrmin[i].r);
			
			if(arrmax[i].pos!=0)
			{
				cnt2 = query(bitmax,arrmax[i].r) - query(bitmax,arrmax[i].l-1);
				ansmax[arrmax[i].pos] = cnt2;
			}
			else
				update(bitmax,size,arrmax[i].r);
		}
		
		for(LI i=1; i<=Q; i++)
		{
			cout << xval[i][1]-xval[i][0]-ansmin[i]-ansmax[i] << "\n";
		}
		
	}

	return 0;
}


