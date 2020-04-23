#include <iostream>
using namespace std;

#define li long int 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    li t;
    cin >> t;
    while(t--)
    {
        string s,r;
        cin >> s >> r;
        li k=0, l = 0;
        li prev=-1;
        for(li i=0; i<s.length(); i++)
        {
            if(s[i]!=r[i]) l++;
            
            if(s[i]!=r[i] && prev==-1)
            {
                prev=i;
                k++;
            }
            
            if(s[i]==r[i])
            {
                prev=-1;
            }
        }
        cout << l*k << "\n";
    }
	return 0;
}

