#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii; // Par (Peso, Vértice)
typedef vector<ii> vii;    // Arreglo de pares
typedef vector<vii> vvii;   // Arreglo de adyacencia

#define INF 20000000

int matriz[1003][1003];
int indice[1003][1003];
int n;
vvii g;   // g: Grafo
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
	while (!pq.empty()) // Mientras haya elementos en la cola..
	{
		int d = pq.top().first;  // d: Distancia
		int v = pq.top().second; // v: Nodo
		pq.pop();
		if (dist[v] >= d) // Pueden haber mejores caminos desde v
			for (int i = 0; i < (int)g[v].size(); i++)
			{
				int u = g[v][i].second;   // Vecino u
				int w = g[v][i].first;    // Peso desde v hacia u
				if (dist[v] + w < dist[u]) // Si existe un mejor camino..
				{
					dist[u] = dist[v] + w;   // Actualizar distancia

					pq.push(ii(dist[u], u)); // Encolar
				}
			}
	}
}

int main()
{
	int c, t ,f;
	cin >> t;
	while (t--)
	{
		cin >> f >> c;
		n = f*c;
		int ind = 0;
		for (int i = 0; i < f; i++)
			for (int e = 0; e < c; e++)
			{
				cin >> matriz[i][e];
				indice[i][e] = ind++;
			}
		g = vvii(n);
		for (int i = 0; i < f; i++)
			for (int e = 0; e < c; e++)
			{
				if (i - 1 >= 0)
					g[indice[i][e]].push_back(ii(matriz[i-1][e], indice[i - 1][e]));
				if (i + 1 < f)
					g[indice[i][e]].push_back(ii(matriz[i+1][e], indice[i + 1][e]));
				if (e - 1 >= 0)
					g[indice[i][e]].push_back(ii(matriz[i][e-1], indice[i][e-1]));
				if (e + 1 < c)
					g[indice[i][e]].push_back(ii(matriz[i][e+1], indice[i][e+1]));
			}
		init();
		dijkstra(0);
		cout << dist[n - 1] + matriz[0][0] << endl;
	}
		
	return 0;
}
