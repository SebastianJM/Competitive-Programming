/* Si existe un Perfect Matching en el grafo bipartito, todos pueden cambiar libros.*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;

int n,r,u,v;
	
vvi g;
vi match; // match[i]: Nodo al que está conectado el nodo i
vb visit; // 0: No visitado, 1: Visitado 

int augmenting(int v) // Busca un augmenting path desde el nodo v
{
  if(visit[v]) // Si el nodo esta visitado..
    return 0;  // No hay augmenting path
  visit[v] = true; // Marcar el nodo como visitado
  for(int i = 0; i < (int)g[v].size(); i++) // Por cada vecino..
  {
    int u = g[v][i]; // u es el vecino en el lado derecho
    // Si el vecino u está libre o si hay un augmenting path
    // a través de este nodo.
    if(match[u] == -1 || augmenting(match[u]))
    {
      match[u] = v; // Asignar el nodo u al nodo v
      return 1;     // El maximum match aumenta en 1
    }
  }
  return 0; // El maximum match no aumenta
}
int MCBM(int left) // left: Número de nodos en el lado izquierdo
{
  int ans = 0;       // Maximum matching es 0
  match = vi(n, -1); // Limpiar arreglo de asignación
  for(int i = 0; i < left; i++) // Por cada nodo en el lado izq..
  {
    visit = vb(left, false); // Limpiar arreglo de visitados
    ans += augmenting(i);      // Buscar augmenting path
  }
  return ans;
}

int main() 
{

	while(cin>>n>>r)
	{
		g=vvi(n);
		for(int i=0;i<r;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
		}
		if(MCBM(n)==n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}