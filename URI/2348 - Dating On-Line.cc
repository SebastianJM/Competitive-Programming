#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0.0)

struct point 
{ 
	double x, y; 
	point(){}
	point(double px,double py):x(px),y(py){}
}; 

point rotate(point p, double theta) // Rota alrededor de (0,0)
{       
	point ans;
	double rad = theta * PI / 180.0; // A Radianes     Matriz de rotacion:
	ans.x = p.x * cos(rad) - p.y * sin(rad);       // [cos(rad) -sin(rad)]
	ans.y = p.x * sin(rad) + p.y * cos(rad);       // [sin(rad)  cos(rad)]
	return ans;
}

double cross(point p, point q) 
{ 
	return p.x * q.y - q.x * p.y; 
}

double area(const vector<point> &p)
{
	int n = (int)p.size();
	double ans = 0.0;
	for(int i = 0; i < n; i++) 
		ans += cross(p[i], p[(i + 1) % n]); // Producto cruz
	return fabs(ans) / 2.0;
}

int main()
{
	int n;
	double v[100005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	vector<point> vp;
	/*7
	12 16 24 35 37 39 50
	v[0]=12;
	v[1]=24;
	v[2]=37;
	v[3]=50;
	v[4]=39;
	v[5]=35;
	v[6]=16;*/
	double ang=360.0/(double)n;
	double it=0.0;
	for(int i=0;i<n;i+=2)
	{
		vp.push_back(rotate(point(0.0,v[i]),it));
		it+=ang;
	}
	for(int i=n-(n&1?2:1);i>0;i-=2)
	{
		vp.push_back(rotate(point(0.0,v[i]),it));
		it+=ang;
	}
	printf("%.3lf\n",area(vp));
	return 0;
}







