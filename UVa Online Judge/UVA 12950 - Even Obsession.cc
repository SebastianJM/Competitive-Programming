#include <bits/stdc++.h>

using namespace std;

#define INF (1<<30)

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vp;
typedef vector<vp> vvi;

int n;
vvi g;   // g: Grafo
vi dist;  // dist[i]: Distancia del origen al nodo i

void init() 
{
  dist = vi(n, INF); // INF : no es posible llegar al nodo
}
void dijkstra(int s) // s: Nodo origen 
{
  priority_queue<ii, vector<ii>, greater<ii> > pq; 
  pq.push(ii(0, s)); // Insertar: (Distancia al origen, origen)
  dist[s] = 0;       // Distancia del origen a si mismo es 0
  while(!pq.empty()) // Mientras haya elementos en la cola..
  {
    int d = pq.top().first;  // d: Distancia
    int v = pq.top().second; // v: Nodo
    pq.pop();
    if(dist[v] >= d) // Pueden haber mejores caminos desde v
      for(int i = 0; i < (int)g[v].size(); i++)
      {
        int u = g[v][i].second;   // Vecino u
        int w = g[v][i].first;    // Peso desde v hacia u
        for(int j=0;j<(int)g[u].size();j++)
        {
        	int u2=g[u][j].second;
        	int w2=g[u][j].first;
	        if(d + w +w2 < dist[u2]) // Si existe un mejor camino..
	        {
	        	
	          dist[u2] = d + w + w2;   // Actualizar distancia
	          pq.push(ii(dist[u2], u2)); // Encolar
	        }
        }
      }
  }
}


int main() 
{
	int r,a,b,w;
	while(cin>>n>>r)
	{
		g=vvi(n);
		for(int i=0;i<r;i++)
		{
			cin>>a>>b>>w;
			a--;b--;
			g[a].push_back(pair<int,int>(w,b));
			g[b].push_back(pair<int,int>(w,a));
		}
		init();
		dijkstra(0);
		cout<<(dist[n-1]==INF?-1:dist[n-1])<<endl;
	}
	return 0;
}