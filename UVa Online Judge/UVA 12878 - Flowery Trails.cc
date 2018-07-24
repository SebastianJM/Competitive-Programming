/* Se basa en el teorema de múltiples caminos mínimos que es:
Si el peso 'w' de una arista con vértices (a,b) + la mínima distancia desde el origen hasta la arista 'a' + la mínima distancia desde el final hasta el vértice 'b' = peso del mínimo camino, entonces esa arista pertenece a un mínimo camino y debe ser contada.
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair <int,int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<bool> vb;

#define INF 20000000

int n,r;
vvii g;
vi dist;
vi prevv;
vi dist_inv;
vi prevv_inv;

void init()
{
    prevv=vi(n,-1);
    dist=vi(n,INF);
}
void dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,s));
    dist[s]=0;
    while(!pq.empty())
    {
        int d=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(dist[v]>=d)
        {
            for(int i=0;i<(int)g[v].size();i++)
            {
                int u=g[v][i].second;
                int w=g[v][i].first;
                if(dist[v]+w<dist[u])
                {
                    dist[u]=dist[v]+w;
                    prevv[u]=v;
                    pq.push(ii(dist[u],u));
                }
            }
        }
    }
}
void init_inv()
{
    prevv_inv=vi(n,-1);
    dist_inv=vi(n,INF);
}
void dijkstra_inv(int s)
{
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,s));
    dist_inv[s]=0;
    while(!pq.empty())
    {
        int d=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(dist_inv[v]>=d)
        {
            for(int i=0;i<(int)g[v].size();i++)
            {
                int u=g[v][i].second;
                int w=g[v][i].first;
                if(dist_inv[v]+w<dist_inv[u])
                {
                    dist_inv[u]=dist_inv[v]+w;
                    prevv_inv[u]=v;
                    pq.push(ii(dist_inv[u],u));
                }
            }
        }
    }
}
int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u,v,w;
    while(cin>>n>>r)
    {
       
       g=vvii(n);
       for(int i=0;i<r;i++)
       {
           cin>>u>>v>>w;
           g[u].push_back(ii(w,v));
           g[v].push_back(ii(w,u));
       }
       init();
       dijkstra(0);
       init_inv();
       dijkstra_inv(n-1);
       int ans=0;
       int comp=dist[n-1];
       for(int i=0;i<n;i++)
       {
           for(int e=0;e<g[i].size();e++)
           {
               if(dist[i]+g[i][e].first+dist_inv[g[i][e].second]==comp)
                 ans+=2*g[i][e].first;
           }
       }
       cout<<ans<<endl;
    }
    
    return 0;
}