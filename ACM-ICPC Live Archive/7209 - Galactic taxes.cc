#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<double,double> Pdd;
typedef pair<double,double> Pdi;
typedef pair<int,Pii> PiPii;
typedef vector<PiPii> VPiPii;
typedef vector<VPiPii> VVPiPii;
typedef vector<int> Vi;
typedef vector<double> Vd;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 100005
#define INF 1e12
#define EPS 1e-7

VVPiPii g;
Vd dist; 
int n;
inline void init() 
{
    dist = Vd(n+1, INF);
}
inline double dijkstra(int s,double t) 
{
    init();
    priority_queue<Pdi,vector<Pdi>,greater<Pdi> > pq; 
    pq.push(Pdi(0.0, s)); 
    dist[s] = 0.0;
    while(!pq.empty())
    {
        double d = pq.top().first; 
        int v = pq.top().second;
        pq.pop(); 
        if(d <= dist[v]) 
        for(int i = 0; i < (int)g[v].size(); i++) 
        {
            int u = g[v][i].first;
            double w = (double)g[v][i].second.first*t+(double)g[v][i].second.second; 
            if(dist[v] + w < dist[u]) 
            {
                dist[u] = dist[v] + w;
                pq.push(Pdd(dist[u], u)); 
            }
        }
    }
    return dist[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);
    int k,u,v,a,b;
    while(cin>>n>>k)
    {
        g=VVPiPii(n+1);
        for(int i=0;i<k;i++)
        {
            cin>>u>>v>>a>>b;
            g[u].pb(PiPii(v,Pii(a,b)));
            g[v].pb(PiPii(u,Pii(a,b)));
        }

		double lo = 0.0, hi = 1440.0;
		for(int i=0;i<100;i++)
		{
			double mid1 = (2*lo + hi) / 3;
			double mid2 = (lo + 2*hi) / 3;
			if(dijkstra(1,mid1) > dijkstra(1,mid2))
				hi = mid2; 
			else 
				lo = mid1;
		}
        printf("%.5lf\n",dijkstra(1,lo));
    }
    
    return 0;
}