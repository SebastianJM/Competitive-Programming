#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-7
struct point 
{ 
	int id;
	double x, y; 
	point(){}
	point(int p_id,double p_x,double p_y):id(p_id),x(p_x),y(p_y){}
};

point pivot;

double distancia(point p, point q) 
{ 
	return hypot(p.x - q.x, p.y - q.y); 
}

int comparar(double d1, double d2)
{
	if(d2 - d1 > EPS) return -1;
	if(d1 - d2 > EPS) return 1;
	return 0;
}

int turn(point p, point q, point r)
{
	double result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
	return comparar(result,0);
}

bool angle_cmp(point a, point b)
{
	if(turn(pivot, a, b) == 0)
		return distancia(pivot, a) < distancia(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return atan2(d1x, d1y) - atan2(d2x, d2y) < 0;
}

bool order_cmp(point a)
{
	return (a.y!=pivot.y)?(a.y<pivot.y):(a.x>pivot.x);
}
int main() 
{
	int t,n,k;
	double x,y;
	vector<point> p;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		p=vector<point>(n,point(0,0.0,0.0));
		pivot=point(0,1000000.0,1000000.0);
		for(int i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
			p[i].id=i+1;
			if(order_cmp(p[i]))
				pivot=p[i];
		}
		sort(p.begin(),p.end(),angle_cmp);
		cout<<p[0].id<<endl;
		for(int i=1;i<k;i++)
			cout<<p[i].id<<endl;
			
		
	}
	
	return 0;
}