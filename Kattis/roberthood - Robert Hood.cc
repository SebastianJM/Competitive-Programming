#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
#define PI (2*acos(0.0))

struct point 
{ 
    double x, y; 
    point(){}
    point(double a,double b):x(a),y(b){}
    point(const point &a):x(a.x),y(a.y){}
};
double distancia(point p, point q) 
{ 
    return hypot(p.x - q.x, p.y - q.y); 
    
}

int comparar(double d1, double d2)
{
    if(d2 - d1 > EPS) return -1; // d2 > d1
    if(d1 - d2 > EPS) return 1; // d1 > d2
    return 0; // d1 == d2
}

int turn(point p, point q, point r)
{
    double result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    return comparar(result, 0);
}
bool cw(point p, point q, point r)
{
    return turn(p, q, r) <= 0;
}
bool cmp(point p1,point p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
vector<point> convexHull(vector<point> P)
{
    int n = (int)P.size(), k = 0;
    vector<point> H(2 * n);
    sort(P.begin(), P.end(),cmp);
    for(int i = 0; i < n; i++) // Hull superior
    {
        while(k >= 2 && cw(H[k - 2], H[k - 1], P[i])) 
            k--;
        H[k++] = P[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) // Hull inferior
    {
        while(k >= t && cw(H[k - 2], H[k - 1], P[i]))
            k--;
        H[k++] = P[i];
    }
    H.resize(k); H.pop_back(); // Eliminamos el ultimo punto
    return H;
}

double cross(point p, point q, point r) // cross product of vectors qr and qp
{
    return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}
double diameterOfPoints(vector<point> P) // Distance of the farthest pair
{
    vector<point> H = convexHull(P); // Modificar método cw: turn(p,q,r) <= 0;
    int n = (int)H.size();
    if(n == 1) return 0; // No hay diametro
    if(n == 2) return distancia(H[0], H[1]); // Devolver la distancia entre si
    double ans = 0;
    for(int k = 0, j = 2; k < n; k++)
    {
        // Encontrar el punto j mas lejano a la linea H[k] -> H[k + 1]
        while(cross(H[(j+1)%n],H[k],H[(k+1)%n]) > cross(H[j],H[k],H[(k+1)%n]))
            j = (j + 1) % n;
        // El punto j es antipodal a los puntos H[k] y H[k + 1]
        ans = max(ans, distancia(H[j], H[k]));
        ans = max(ans, distancia(H[j], H[(k + 1) % n]));
        // Si el punto j + 1 esta a la misma distancia, tambien es un antipodal
        if(cross(H[(j+1)%n], H[k], H[(k+1)%n]) == cross(H[j], H[k], H[(k+1)%n]))
        {
            ans = max(ans, distancia(H[(j + 1) % n], H[k]));
            ans = max(ans, distancia(H[(j + 1) % n], H[(k + 1) % n]));
        }
    }
    return ans;
}
int main() 
{
    int n;
    cin>>n;
    vector<point> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].x>>v[i].y;
    
    printf("%.8lf\n",diameterOfPoints(v));
    return 0;
}