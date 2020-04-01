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
        LI N, P;
        cin >> N >> P;
        
        VEC(LI) arr(N);
        LI idx = -1;
        for(LI i=0; i<N; i++)
        {
            cin >> arr[i];
            if(P%arr[i])
                idx = i;
        }
        
        if(idx!=-1)
        {
            cout << "YES ";
            for(LI i=0; i<N; i++)
                if(i==idx)
                    cout << (P/arr[i] + 1) << " ";
                else
                    cout << "0 ";
        }
        else
        {
            
            LI first=0,second=0;
            int flag = 0;
            LI ss,ff;
            while(first < N)
            {
                flag = 0;
                second = first+1;
                while(second < N)
                {
                    if(arr[second]%arr[first]!=0)
                    {
                       flag = 1;
                       break;
                    }
                    second++;
                }
                
                if(flag==1)
                    break;
                    
                first++;
            }
            
            
            if(flag)
            {
                cout << "YES ";
                ss = (P/arr[second] - 1);
                ff = ((P-(ss*arr[second]))/arr[first] + 1);
                     
                for(LI i=0; i<N; i++)
                    if(i==first)
                        cout << ff << " ";
                    else if(i==second)
                        cout << ss << " ";
                    else
                        cout << "0 ";
            }
            else
                cout << "NO";
            
        }
        
        cout << "\n";
    }


	return 0;
}


