#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = 200000000;
const int MAX = 10005;
#define EPS 1e-07
 
struct Point { double x, y; Point(){} Point(double px,double py):x(px),y(py){}};
 
vi pset; // pset[i]: Boss of node i
vi sset; // sset[i]: Number of nodes that depend on node i
int nSets; // Total number of sets
void init(int n) // n: Number of nodes
{
    sset = vi(n, 1); // Each set has size one
    pset = vi(n, 0); // Assign capacity for n nodes
    for(int i = 0; i < n; i++) // For each node i..
        pset[i] = i; // Node i is its own boss
}
int findSet(int i) // Returns the final boss of node i
{
    return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) // Checks if two nodes belong to the same set
{
    return findSet(i) == findSet(j); // Check if nodes have the same boss
}
void unionSet(int i, int j) // Joins the sets of node i and node j
{
    if(!isSameSet(i, j)) // If the nodes belong to different sets..
    {
        sset[findSet(j)] += sset[findSet(i)]; // Increase set where j
        pset[findSet(i)] = findSet(j); // Boss of i changes to boss of j
    }
}
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,q,a,b,c,d;
    vector<pair<Point,Point> > vec;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        init(n);
        vec=vector<pair<Point,Point> >(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i].first.x>>vec[i].first.y>>vec[i].second.x>>vec[i].second.y;
            for(int e=0;e<i;e++)
                if(doIntersect(vec[e].first,vec[e].second,vec[i].first,vec[i].second))
                    unionSet(e,i);
        }
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            if(isSameSet(a-1,b-1))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    
    
    return 0;
} 