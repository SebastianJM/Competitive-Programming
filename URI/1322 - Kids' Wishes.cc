#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair <bool, int> ii;
typedef vector<ii> vii;

vvi g;
vi color;
vi padre;
int ciclo;
int n;
bool ans;

bool dfs_visit(int v, int p) // v: Vértice
{
	color[v] = 1;     // Marcar el vértice como visitado
	// Asumir que no hay ciclo
	for (int i = 0; i < (int)g[v].size() && !ans; i++)
	{
		int u = g[v][i];  // Ir al vecino u
		
		if(ans)
			return true;
		if (color[u] == 0) // Si el vértice no ha sido visitado..
		{
			if(padre[u]==-1)
				padre[u] = padre[v] + 1;
			ans = dfs_visit(u, v);  // Ir al vértice
		}
		else if (color[u] > 0 && u != p) // Hay un back-edge
		{                  // Encontramos un ciclo
			ciclo = abs(padre[v] - padre[u]) + 1;
			if(ciclo>2 && ciclo!=n)
			{
				ans=true;
				return true;
			}
		}	
	}
	color[v] = 2; // Marcar el vértice v como procesado
	return ans;   // Devolver resultado
}

bool hasCycle(int nn) // n: Cantidad de vértices del grafo
{
	color = vi(nn, 0); // Ningún vértice ha sido visitado
	padre = vi(nn, -1);
	padre[0]=0;
	ans = false; 
	for (int i = 0; i < nn; i++)             // Para cada nodo..
		if (dfs_visit(i, -1)) // No ha sido visitado
			if(ans)
				return true;
	return false; // No existe un ciclo
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int  q, u, v;

	while (1)
	{
		cin >> n >> q;
		if (n == 0 && q == 0)
			return 0;
		map<int, int> gg;
		int e = 0;
		g = vvi(2 * q + 1);
		for (int i = 0; i<q; i++)
		{
			cin >> u >> v;
			if (gg.find(u) == gg.end())
				gg[u] = e++;
			if (gg.find(v) == gg.end())
				gg[v] = e++;
			g[gg[u]].push_back(gg[v]);
			g[gg[v]].push_back(gg[u]);
		}

		for(int i = 0;i <e;++i)
		{
            sort(g[i].begin(),g[i].end());
            g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
        }
        bool rep=false;
        for(int i = 0;i < e;++i)
            if(g[i].size() > 2)
			{
                rep=true;   
				break;
			}
        if(rep)
		{
            cout<<"N"<<endl;
            continue;
        }
		if(gg.size()>0)
		{
			bool res = hasCycle(gg.size());
			if(res)
				cout<<"N"<<endl;
			else
				cout<<"Y"<<endl;
		}
		else
			cout<<"Y"<<endl;
	}
	return 0;
}
