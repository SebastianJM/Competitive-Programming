#include <bits/stdc++.h>

using namespace std;
typedef vector<pair<double,double>> vdd;
typedef pair<double,double> dd;

typedef priority_queue< dd> pq;

#define EPS 1e-07

struct point{double x,y;};
struct line{double a,b,c;};

void points_to_line(point p1,point p2,line *L)
{
    if(p1.x==p2.x)
    {
        L->a=1;
        L->b=0;
        L->c=-p1.x;
    }
    else
    {
        L->a=-(p1.y-p2.y) / (p1.x-p2.x);
        L->b=1;
        L->c=-(L->a*p1.x)-(L->b*p1.y);
    }
}

double cross(point p,point q){return p.x*q.y-q.x*p.y;}

double dist(point p,point q){return hypot(p.x-q.x,p.y-q.y);}

bool intersection_point(line L1,line L2,point *p)
{
    p->x=(L2.b*L1.c-L1.b*L2.c)/(L2.a*L1.b-L1.a*L2.b);
    if(fabs(L1.b)>EPS)
        p->y=-(L1.a*p->x+L1.c)/L1.b;
    else
        p->y=-(L2.a*p->x+L2.c)/L2.b;
    return true;
}

double area(const vector<point> &p)
{
    int n=(int)p.size();
    double ans=0.0;
    for(int i=0;i<n;i++)
        ans+=cross(p[i],p[(i+1)%n]);
    return fabs(ans)/2.0;
}

double perimeter(const vector<point> &p)
{
    int n=(int)p.size();
    double ans=0.0;
    for(int i=0;i<n;i++)
        ans+=dist(p[i], p[(i+1)%n]);
    return ans;
}

double toAlgo(double a){
    return ((int)((a*1000.0)+0.5))/1000.0;
    
}
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
            return 0;
        vector<point> vec=vector<point>(n);
        for(int i=0;i<n;i++)
            cin>>vec[i].x>>vec[i].y;
        int res = (int)(area(vec)+0.05);
        cout<<res<<endl;
        
    }
  
    return 0;
}