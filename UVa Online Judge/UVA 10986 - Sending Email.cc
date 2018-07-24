#include "stdio.h"
#include <vector>
#include <queue>
#include <functional>

#define INF 1000000000

using namespace std;

typedef pair<int,int> Pii;
typedef vector<Pii> VPii;
typedef vector<int> Vi;
typedef vector<VPii> GPii;

Vi v_distancia;
Vi v_padres;

int main()
{
	int num_nodos,num_relaciones,origen,destino,peso,test;
	int u,v;
	int contador=0;
	scanf("%d",&test);
	while(contador!=test)
	{
		scanf("%d %d %d %d", &num_nodos, &num_relaciones,&origen,&destino);

		GPii Grafo(num_nodos);

		for(int i = 0;i<num_relaciones;i++)
		{
			scanf("%d %d %d", &u, &v, &peso);
			Grafo[u].push_back(Pii(v,peso));
			Grafo[v].push_back(Pii(u,peso));	
		}

		v_distancia=Vi(num_nodos,INF);
		v_padres=Vi(num_nodos, -1);
		priority_queue<Pii, vector<Pii>, greater<Pii>> heap;

		int nodo_inicial = origen;
		v_distancia[nodo_inicial] = 0;
		heap.push(Pii(v_distancia[nodo_inicial],nodo_inicial));

		while(!heap.empty())
		{
			Pii top=heap.top(); heap.pop();
			int nodo=top.second;
			int distancia=top.first;

			if(v_distancia[nodo] >= distancia)
			{
				for(int i=0;i<Grafo[nodo].size();i++)		
				{
					int nodo_adyacente=Grafo[nodo][i].first;
					int peso_al_adyacente=Grafo[nodo][i].second;

					if(v_distancia[nodo_adyacente] > v_distancia[nodo]+peso_al_adyacente)
					{
						v_distancia[nodo_adyacente]=v_distancia[nodo]+peso_al_adyacente;
						v_padres[nodo_adyacente]=nodo;
						heap.push(Pii(v_distancia[nodo_adyacente],nodo_adyacente));
					}
				}
			}
		}
		if(v_distancia[destino]==INF)
			printf("Case #%d: unreachable\n",contador+1);
		else
			printf("Case #%d: %d\n",contador+1,v_distancia[destino]);
		contador++;
	}

	return 0;
}