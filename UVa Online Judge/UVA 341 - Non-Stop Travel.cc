#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

typedef pair<int,int> Pi;
typedef vector<Pi> VPi;
typedef vector<VPi> GPi;
typedef vector<int> Vi;
typedef stack<int> Si;

#define INF 1000000

GPi grafo;
Vi v_distancia;
Vi v_padres;
Si camino;

int main()
{
	int num_nodos;
	int ite;
	int v,peso;
	int origen,destino;
	int test=1;
	while(true)
	{
		scanf("%d",&num_nodos);
		
		if(num_nodos==0)
			break;
		grafo=GPi(num_nodos+1);
		v_distancia=Vi(num_nodos+1,INF);
		v_padres=Vi(num_nodos+1,-1);
		camino=Si();
		
		for(int i=1;i<=num_nodos;i++)
		{
			scanf("%d",&ite);
			for(int e=0;e<ite;e++)
			{
				scanf("%d %d",&v,&peso);
				grafo[i].push_back(Pi(v,peso));
			}
		}
		
		scanf("%d %d",&origen,&destino);
		priority_queue<Pi,vector<Pi>,greater<Pi>> heap;
		v_distancia[origen]=0;
		heap.push(Pi(origen,v_distancia[origen]));

		while(!heap.empty())
		{
			Pi aux=heap.top();
			heap.pop();
			int nodo=aux.first;
			int distancia=aux.second;
			if(v_distancia[nodo]>=distancia)
			{
				for(int i=0;i<grafo[nodo].size();i++)
				{
					int nodo_adyacente=grafo[nodo][i].first;
					int peso_adyacente=grafo[nodo][i].second;
					if(v_distancia[nodo_adyacente]>v_distancia[nodo]+peso_adyacente)
					{
						v_distancia[nodo_adyacente]=v_distancia[nodo]+peso_adyacente;
						v_padres[nodo_adyacente]=nodo;
						heap.push(Pi(nodo_adyacente,v_distancia[nodo_adyacente]));
					}
				}
			}
		}
		int aux=v_padres[destino];
		camino.push(destino);
		while(aux!=-1)
		{
			camino.push(aux);
			aux=v_padres[aux];
		}
			
		printf("Case %d: Path =",test);
		while(!camino.empty())
		{
			printf(" %d",camino.top());
			camino.pop();
		}
		printf("; %d second delay\n",v_distancia[destino]);
		test++;
	}
	return 0;
}