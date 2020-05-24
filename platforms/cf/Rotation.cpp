#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	float k;
	cin >> k;
	k = k*PI/180;
	float x,y;
	cin >> x >> y;
	float l = sqrt(x*x + y*y);
	
	float theta = atan(y/x);
	float xn = l*cos(theta + k);
	
	float yn = l*sin(theta+k);
	
	cout << fixed << setprecision(2) << xn << " " << yn;

	return 0;
}


