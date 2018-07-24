#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

#define INF 10000000
using namespace std;

typedef vector<int> Vi;
typedef pair<int,int> Pi;
typedef pair<int,Pi> PPi;
typedef vector<PPi> Pii;
typedef vector<Pii> VPii;

Vi pesos;
VPii grafo;

int main()
{
	int u,v,peso;
	int ult,aux2;
	int num_ascen,piso_final;
	char aux;
	
	while(scanf("%d %d",&num_ascen,&piso_final)!=EOF)
	{
		grafo=VPii(100);
		pesos=Vi(num_ascen);
		for(int i=0;i<num_ascen;i++)
		{
			scanf("%d",&peso);
			pesos[i]=peso;
		}
		for(int i=0;i<num_ascen;i++)
		{
			scanf("%d",&ult);
			while(true)
			{	
				scanf("%c",&aux);
				if(aux==10)
					break;
				scanf("%d",&aux2);		
				grafo[ult].push_back(PPi(i,Pi(aux2,(aux2-ult)*pesos[i])));
				ult=aux2;
			}
		}
		Vi v_distancia(100,INF);
		Vi v_padres(100, -1);
		
		priority_queue<PPi, vector<PPi>, greater<PPi>> heap;

		int nodo_inicial = 0;
		int elevador=grafo[0][0].first;
		v_distancia[nodo_inicial] = 0;
		heap.push(PPi(elevador,Pi(nodo_inicial,v_distancia[nodo_inicial])));
		int aux_elev;
		while(!heap.empty())
		{
			PPi top = heap.top(); heap.pop();
			int nodo = top.second.first;
			int distancia = top.second.second;
			elevador=top.first;

			/*if(v_distancia[nodo] >= distancia)
			{*/
				for(int i=0;i<grafo[nodo].size();i++)		
				{
					int nodo_adyacente = grafo[nodo][i].second.first;
					int peso_al_adyacente;

					if(grafo[nodo][i].first!=elevador)
					{
						peso_al_adyacente = grafo[nodo][i].second.second+60;
						elevador=grafo[nodo][i].first;
					}
					else
						peso_al_adyacente = grafo[nodo][i].second.second;

					if(v_distancia[nodo_adyacente] > v_distancia[nodo] + peso_al_adyacente)
					{
						v_distancia[nodo_adyacente] = v_distancia[nodo] + peso_al_adyacente;
						v_padres[nodo_adyacente] = nodo;
						heap.push(PPi(elevador,Pi(nodo_adyacente,v_distancia[nodo_adyacente])));
					}
					elevador=top.first;
				}
			
		}

		if(v_padres[piso_final]==-1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",v_distancia[piso_final]);
	}
	return 0;
}
