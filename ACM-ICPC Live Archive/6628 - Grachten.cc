#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-07
 
struct point 
{ 
	double x, y; 
	point(double px,double py):x(px),y(py){}
	point(){}
}; 
struct line { double a, b, c; 
line(){}}; 
 
void points_to_line(point p1, point p2, line *L)
{
  if(p1.x == p2.x) // Caso especial: x = k
  { 
    L->a = 1; 
    L->b = 0; 
    L->c = -p1.x; 
  }
  else // Caso general: y = mx + k                                 
  {
    L->a = -(p1.y - p2.y) / (p1.x - p2.x); // -mx + y – k = 0; a = -m
    L->b = 1;                              // -mx + y – k = 0; b = 1
    L->c = -(L->a * p1.x) - (L->b * p1.y); // c = -ax - by
  }
}
 
bool parallel(line L1, line L2) 
{
  return (fabs(L1.a - L2.a) <= EPS) && (fabs(L1.b - L2.b) <= EPS);
}
 
bool same_line(line L1,line L2)
{
  return parallel(L1, L2) && fabs(L1.c - L2.c) <= EPS;
}
 
bool intersection_point(line L1, line L2, point *p) // Resolver SEL
{
  if(same_line(L1,L2)) return false; // Misma linea
  if(parallel(L1,L2))  return false; // Lineas paralelas 
  p->x = (L2.b * L1.c - L1.b * L2.c) / (L2.a * L1.b - L1.a * L2.b);
  if(fabs(L1.b) > EPS)
    p->y = - (L1.a * p->x + L1.c) / L1.b;
  else 
    p->y = - (L2.a * p->x + L2.c) / L2.b;
  return true;
}
 
long long gcd(long long a, long long b)
{
	return (b == 0) ? a : gcd(b, a % b);
}
 
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double AB,AC,BD;
	while(cin>>AB>>AC>>BD)
	{
		point A(0.0,AB);
		point B(0.0,0.0);
		point C(AC,AB);
		point D(BD,0.0);
		line A_B;
		line C_D;
		points_to_line(A,B,&A_B);
		points_to_line(C,D,&C_D);
		point T;
		intersection_point(A_B,C_D,&T);
 
		long long det=AB*AC;
		long long in=BD-AC;
		cout<<det/gcd(det,in)<<"/"<<in/gcd(det,in)<<endl;
	}
	return 0;
}