#include <bits/stdc++.h>
using namespace std;

struct point
{
	double x,y;
	point(){}
	point(double xx,double yy){x=xx;y=yy;}
};
#define EPS 1e-07

double dist(point p,point q)
{
	return hypot(p.x-q.x,p.y-q.y);
}
double distToLine(point p, point A, point B)
{
	point c;
   // Distancia de p a la línea AB. El punto mas cercano se guarda en c 
   double scale = (double) 
       ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) / 
       ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
   c.x = A.x + scale * (B.x - A.x);
   c.y = A.y + scale * (B.y - A.y);
   return dist(p,c);
}

double distToLineSegment(point p, point A, point B)
{
   // Distancia de p al segmento AB. El punto mas cercano se guarda en c
   point c;
   if((B.x - A.x) * (p.x - A.x) + (B.y - A.y) * (p.y - A.y) < EPS)
   {
      c.x = A.x; c.y = A.y;
      return dist(p, A);
   }
   if((A.x - B.x) * (p.x - B.x) + (A.y - B.y) * (p.y - B.y) < EPS)
   {
      c.x = B.x; c.y = B.y;
      return dist(p, B);
   }
   return distToLine(p, A, B);
}

int main() 
{
	double n,alto,ancho,yf1,xi1,yi1,yf2,xi2,yi2;
	double ans,a;
	while(cin>>n)
	{
		cin>>ancho>>alto;
		cin>>yf1>>xi1>>yi1;
		ans=ancho-xi1;
		for(int i=0;i<n-1;i++)
		{
			cin>>yf2>>xi2>>yi2;
			a=distToLineSegment(point(xi1,yi1),point(i%2==0?ancho:0,yf2),point(xi2,yi2));
			ans=min(ans,a);
			ans=min(ans,i%2==0?xi2:ancho-xi2);
			yf1=yf2;
			xi1=xi2;
			yi1=yi2;
		}
		printf("%.2f\n",ans);
	}
	return 0;
}