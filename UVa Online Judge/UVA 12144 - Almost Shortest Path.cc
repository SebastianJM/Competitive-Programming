#include <bits/stdc++.h>
using namespace std;

#define INF 20000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;    
typedef vector<vii> vvii;   
vvii g;
vvii gI;
vi dist;  
vi prevv;  
vi distI;
vi prevI;
int n,c;

void init() 
{
  prevv = vi(n, -1);  
  dist = vi(n, INF); 
  prevI = vi(n, -1);  
  distI = vi(n, INF); 
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
        if(dist[v] + w < dist[u]) // Si existe un mejor camino..
        {
          dist[u] = dist[v] + w;   // Actualizar distancia
          prevv[u] = v;             // Actualizar padre
          pq.push(ii(dist[u], u)); // Encolar
        }
      }
  }
}

void dijkstraI(int s) // s: Nodo origen 
{
  priority_queue<ii, vector<ii>, greater<ii> > pq; 
  pq.push(ii(0, s)); // Insertar: (Distancia al origen, origen)
  distI[s] = 0;       // Distancia del origen a si mismo es 0
  while(!pq.empty()) // Mientras haya elementos en la cola..
  {
    int d = pq.top().first;  // d: Distancia
    int v = pq.top().second; // v: Nodo
    pq.pop();
    if(distI[v] >= d) // Pueden haber mejores caminos desde v
      for(int i = 0; i < (int)gI[v].size(); i++)
      {
        int u = gI[v][i].second;   // Vecino u
        int w = gI[v][i].first;    // Peso desde v hacia u
        if(distI[v] + w < distI[u]) // Si existe un mejor camino..
        {
          distI[u] = distI[v] + w;   // Actualizar distancia
          prevI[u] = v;             // Actualizar padre
          pq.push(ii(distI[u], u)); // Encolar
        }
      }
  }
}

int main()
{
	int a,b,p,origen,destino;
	while(1)
	{
		cin>>n>>c;
		if(!n && !c)
			break;
		cin>>origen>>destino;
		init();
		g=vvii(n);
		gI=vvii(n);
		for(int i=0;i<c;i++)
		{
			cin>>a>>b>>p;
			g[a].push_back(ii(p,b));
			gI[b].push_back(ii(p,a));
		}
		dijkstra(origen);
		dist[origen]=0;
		dijkstraI(destino);
		distI[destino]=0;
		for(int i=0;i<n;i++)
		{
			for(int e=0;e<g[i].size();e++)
			{
				if(dist[i]+g[i][e].first+distI[g[i][e].second]==dist[destino])
					g[i][e].first=INF;
			}
		}
		init();
		dijkstra(origen);
		if(dist[destino]==INF)
			cout<<-1<<endl;
		else
			cout<<dist[destino]<<endl;
	}
	return 0;
}