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

int n=20;
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
	int a, b,c,t=1;
	while (cin >> a)
	{
		g = vvii(20);
		cout << "Test Set #" << t++ << endl;
		for (int i = 0; i < 19; i++)
		{
			for (int e = 0; e < a; e++)
			{
				cin >> b;
				g[i].push_back(ii(1,b - 1));
				g[b - 1].push_back(ii(1, i));
			}
			cin >> a;
		}
		for (int i = 0; i < a; i++)
		{
			cin >> b >> c;
			init();
			dijkstra(b - 1);
			printf("%2d to %2d: %d\n", b, c,dist[c-1]);
		}
		cout << endl;
	}
	return 0;
}
