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
    point p1,p2,p3,p4,medio;
    while(1)
    {
        pq cola = pq();
        cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
        if(p1.x==0.0 && p1.y==0.0 && p2.x==0.0 && p2.y ==0.0 && p3.x==0.0 && p3.y==0.0 && p4.x==0.0 && p4.y==0.0)
            return 0;
        line l1,l2;
        points_to_line(p1,p3,&l1);
        points_to_line(p2,p4,&l2);
        bool h=intersection_point(l1,l2,&medio);
        
        vector<point> v1,v2,v3,v4;
        v1.push_back(p1);
        v1.push_back(p2);
        v1.push_back(medio);
        
        v2.push_back(p2);
        v2.push_back(p3);
        v2.push_back(medio);
        
        v3.push_back(p3);
        v3.push_back(p4);
        v3.push_back(medio);
        
        v4.push_back(p4);
        v4.push_back(p1);
        v4.push_back(medio);
        
        vector<pair<double,double>> res=vector<pair<double,double>>(4);
        res[0].first=toAlgo(area(v1));
        res[0].second=toAlgo(perimeter(v1));
        cola.push(res[0]);
        res[1].first=toAlgo(area(v2));
        res[1].second=toAlgo(perimeter(v2));
        cola.push(res[1]);
        res[2].first=toAlgo(area(v3));
        res[2].second=toAlgo(perimeter(v3));
        cola.push(res[2]);
        res[3].first=toAlgo(area(v4));
        res[3].second=toAlgo(perimeter(v4));
        cola.push(res[3]);
        
        for(int i=0;i<4;i++){
            dd res = cola.top(); cola.pop();
            if(i!=0) printf(" ");
            printf("%.3f %.3f",res.first,res.second);
            //cout<<res.first<<" "<<res.second<<" ";
        }
        printf("\n");
        
    } 
    
    return 0;
}