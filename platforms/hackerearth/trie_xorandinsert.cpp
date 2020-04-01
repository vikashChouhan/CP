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

#define li long int 


struct node {
    int val=0;
    node *child[2]={NULL,NULL};
    
    bool leaf=false;
    li data=INT_MAX;
    node(int v)
    {
        val = v;
    }
    
}*root=NULL;

li mm = 0;
void insert(int x)
{
    if(x==0)
    {
        root->child[0] = new node(0);
        return;
    }
    
    node *p = root;
    li temp = x;
    while(x>0)
    {
        if(p->child[x%2]==NULL)
            p->child[x%2] = new node(x%2);
        
        p = p->child[x%2];
        x/=2;
    }
   
   p->leaf = true;
   p->data = temp;
   mm = min(mm,p->data);
}

node * doxor(node *root,int x)
{
    if(root!=NULL && x>0)
    {
        root->val ^= (x%2);
        if(root->leaf)
        {
            root->data ^= root->val;
            mm = min(mm,root->data);
        }
        root->child[0] = doxor(root->child[0],x/2);
        root->child[1] = doxor(root->child[1],x/2);
    }
    
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    li q;
    cin >> q;
    root = new node(0);
    insert(0);
    while(q--)
    {
        int type;
        li x;
        cin >> type;
        if(type==1)
        {
            cin >> x;
            insert(x);
        }
        else if(type==2)
        {
            cin >> x;
            root->child[0] = doxor(root->child[0],x);
            root->child[1] = doxor(root->child[1],x);
        }
        else
        {
            cout << mm << "\n";
        }
    }
}
