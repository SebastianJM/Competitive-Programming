#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0.0)

struct point
{
	double x,y;
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

int main() 
{
	double r,n;
	point p1,p2;
	while(cin>>r>>n)
	{
		p1=point(0,r);
		p2=rotate(p1,360.0/n);
		double a=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
		double b=sqrt((p1.x)*(p1.x)+(p1.y)*(p1.y));
		double c=sqrt((p2.x)*(p2.x)+(p2.y)*(p2.y));
		double s=(a+b+c)/2;
		printf("%.3lf\n",sqrt(s*(s-a)*(s-b)*(s-c))*n);
	}
	return 0;
}