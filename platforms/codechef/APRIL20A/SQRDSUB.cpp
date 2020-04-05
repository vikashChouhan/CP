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

#define MAX 100002

#define um unordered_map<long int, long int>
unordered_map<long int, long int> k_cnt_4, current_map_4, cnts_4[MAX]; 
unordered_map<long int, long int> k_cnt_2, current_map_2, cnts_2[MAX]; 


LL countSubarrays(long int* arr, long int n, long int k, um &k_cnt,um &current_map,um *cnts) 
{ 
  
    if(k==2) {
        k_cnt[2]++;
    }
    else if(k==4) {
        k_cnt[2]=2;
    }
    long int l = 0, r = 0; 
  
    LL ans = 0; 
  
    while (r < n) { 
  
        if(arr[r]%2==0)
        {
            current_map[2] += (int)log2(arr[r]&(-arr[r]));
            cnts[r][2] += (int)log2(arr[r]&(-arr[r]));
            arr[r] >>= (int)log2(arr[r]&(-arr[r]));
        }
        long int flag = 0; 
       
        if (current_map[2] < k_cnt[2]) { 
            flag = 1; 
        } 
  
        if (!flag) { 
            ans += n - r; 
            current_map[2] -= cnts[l][2]; 
            l++; 
        } 
        else { 
            r++; 
        } 
    } 
  
    return ans; 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	LI t;
	cin >> t;

	while(t--)
	{
		LI N;
		cin >> N;
		LI arr[N],arr1[N];
		LI evenidx=-1,twos=0;
		for(LI i=0; i<N; i++)
		{
			cin >> arr[i];
			arr1[i]=arr[i];
			cnts_4[i].clear();
			cnts_2[i].clear();
		}
        
		k_cnt_4.clear();current_map_4.clear();
		k_cnt_2.clear();current_map_2.clear();
	    twos = countSubarrays(arr1,N,2,k_cnt_2,current_map_2,cnts_2);
		LL fours = countSubarrays(arr,N,4,k_cnt_4,current_map_4,cnts_4);
		cout << (N*(N+1))/2 - twos + fours << "\n";
	}

	return 0;
}


