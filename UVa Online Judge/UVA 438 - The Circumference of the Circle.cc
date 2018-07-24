
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0.0)
int main() 
{
	double x1,x2,x3,y1,y2,y3;

	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		// Teorema de Heron
		double A=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		double B=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		double C=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		double S=(A+B+C)/2;
		double d=A*B*C/(sqrt(S*(S-A)*(S-B)*(S-C))*2);
		printf("%.2lf\n",PI*d);
	}
	
	return 0;
}

// Innecesariamente largo:

#include <bits/stdc++.h>

using namespace std;
typedef vector<pair<double,double>> vdd;
typedef pair<double,double> dd;

typedef priority_queue< dd> pq;

#define EPS 1e-07
#define PI (2*acos(0.0))

struct point{double x,y;};
struct line{double a,b,c;};

void points_to_line(point p1,point p2,line *L)
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

double cross(point p,point q){return p.x*q.y-q.x*p.y;}

double dist(point p,point q){return hypot(p.x-q.x,p.y-q.y);}

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



bool center_from_3points(point p1, point p2, point p3, point *c)
{
   point a1, a2; // a1: midpoint of line p2p3, a2: midpoint of line p1p3
   a1.x = (p2.x + p3.x) * 0.5;  a1.y = (p2.y + p3.y) * 0.5;
   a2.x = (p1.x + p3.x) * 0.5;  a2.y = (p1.y + p3.y) * 0.5;
   point b1, b2; // b1: point on the line a1c (use congruent triangles)
   b1.x = a1.x - (p3.y - p2.y);  b1.y = a1.y + (p3.x - p2.x);
   b2.x = a2.x - (p3.y - p1.y);  b2.y = a2.y + (p3.x - p1.x);
   line L1, L2; // perpendicular lines to p2p3 and p1p3 respectively
   points_to_line(a1, b1, &L1);
   points_to_line(a2, b2, &L2);
   return intersection_point(L1, L2, c);

}


int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    point p1,p2,p3;
    while(cin>>p1.x>>p1.y)
    {
        cin>>p2.x>>p2.y>>p3.x>>p3.y;
		point medio;
		center_from_3points(p1,p2,p3,&medio);
		double radio=dist(p1,medio);
		printf("%.2f\n",2*radio*PI);
    }
    return 0;
}