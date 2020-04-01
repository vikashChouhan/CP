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

struct Point {
	LI x;
	LI y;
	Point(LI xx,LI yy){
		x = xx;y = yy;
	}
	bool operator==(Point pt){
		return pt.x==x && pt.y==y;
	}
};
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;
  
    return (val > 0)? 1: 2;
} 
   
bool intersect(Point p1, Point q1, Point p2, Point q2) 
{ 

    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
    if (o1 != o2 && o3 != o4) 
        return true; 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	
	while(t--)
	{
		LI N, Q;
		cin >> N >> Q;
		
		LI x;
		VEC(Point) pts;
		for(LI i=1; i<=N; i++)
		{
			cin >> x;
			pts.push_back(Point(i,x));
		}
		LI x1,x2,y;
		
		while(Q--)
		{
			
			cin >> x1 >> x2 >> y;
			Point p1 = Point(x1,y);
			Point p2 = Point(x2,y);
			LI ans = 0;
			
			Point left(0,0),right(0,0);
			for(LI i=1; i<N; i++)
			{
				if(pts[i].x > pts[i-1].x)
				{
					left = pts[i-1];
					right = pts[i];
				}
				else
				{
					left = pts[i];
					right = pts[i-1];
				}
				
				if(p1==right || p2==left) continue;
				else if(intersect(p1,p2,pts[i-1],pts[i]))
					ans++;
			}
			cout << ans << "\n";
		}
	}

	return 0;
}


