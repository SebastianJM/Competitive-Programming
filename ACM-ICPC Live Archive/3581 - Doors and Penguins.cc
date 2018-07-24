#include <bits/stdc++.h>

using namespace std;
typedef vector<pair<double,double>> vdd;
typedef pair<double,double> dd;

typedef priority_queue< dd> pq;

#define EPS 1e-07
#define PI (2*acos(0.0))

struct point{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
        
};
struct line{int a,b,c;};


int comparar(double d1,double d2)
{
    if(d2-d1>EPS) return -1;
    if(d1-d2>EPS) return 1;
    return 0;
}
double dot(point p,point q){return p.x*q.x+p.y*q.y;}

double norm(point p){return p.x*p.x+p.y*p.y;}

double cross(point p,point q,point r){
    return (r.x-q.x)*(p.y-q.y)-(r.y-q.y)*(p.x-q.x);
}
double angle(point a,point o,point b)
{
    point u(a.x-o.x,a.y-o.y);
    point v(b.x-o.x,b.y-o.y);
    return acos(dot(u,v) /sqrt(norm(u)*norm(v)));
}

bool inPolygon(point p,vector<point> P)
{
    double sum=0.0;
    int n=(int)P.size();
    for(int i=0;i<n;i++)
        if(cross(p,P[i],P[(i+1)%n])<0)
            sum-=angle(P[i],p,P[(i+1)%n]);
        else 
            sum+=angle(P[i],p,P[(i+1)%n]);
    return fabs(fabs(sum)-2*PI)<EPS;
}

int turn(point p,point q,point r)
{
    double result=(r.x-q.x)*(p.y-q.y)-(r.y-q.y)*(p.x-q.x);
    return comparar(result,0);
}

bool cw(point p,point q,point r)
{
    return turn(p,q,r)<0;
}

bool cmp(point p1,point p2)
{
    return p1.x<p2.x||(p1.x==p2.x && p1.y<p2.y);
}

vector<point> convexHull(vector<point> P)
{
    int n=(int)P.size(),k=0;
    vector<point> H(2*n);
    sort(P.begin(),P.end(),cmp);
    for(int i=0;i<n;i++)
    {
        while(k>=2 && cw(H[k-2],H[k-1],P[i])) k--;
        H[k++]=P[i];
    }
    for(int i=n-2,t=k+1;i>=0;i--)
    {
        while(k>=t && cw(H[k-2],H[k-1],P[i])) k--;
        H[k++]=P[i];
    }
    H.resize(k); H.pop_back();
    return H;
}

int main()
{
    int d,p,x1,y1,x2,y2,t=1;
    while(1)
    {
        cin>>d>>p;
        if(d==0 && p==0)
            return 0;
        vector<point> doors;
        vector<point> penguins;
        for(int i=0;i<d;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            point p1(x1,y1);
            doors.push_back(p1);
            point p2(x2,y2);
            doors.push_back(p2);
            point p3(x2,y1);
            doors.push_back(p3);
            point p4(x1,y2);
            doors.push_back(p4);
        }
        for(int i=0;i<p;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            point p1(x1,y1);
            penguins.push_back(p1);
            point p2(x2,y2);
            penguins.push_back(p2);
            point p3(x2,y1);
            penguins.push_back(p3);
            point p4(x1,y2);
            penguins.push_back(p4);
        }
        vector<point> condor=convexHull(doors);
        vector<point> conpen=convexHull(penguins);
        
        bool cumple=false;
        for(int i=0;i<condor.size();i++)
        {
            if(inPolygon(condor[i],conpen))
            {
                cumple=true;
                break;
            }
        }
        if(!cumple)
        {
            for(int i=0;i<conpen.size();i++)
            {
                if(inPolygon(conpen[i],condor))
                {
                    cumple=true;
                    break;
                }
            }
        }
        if(t!=1) cout <<endl;
        if(!cumple)
            cout<<"Case "<<t<<": It is possible to separate the two groups of vendors."<<endl;
        else
            cout<<"Case "<<t<<": It is not possible to separate the two groups of vendors."<<endl;           
        
        t++;   
        
    }
  
    return 0;
}

