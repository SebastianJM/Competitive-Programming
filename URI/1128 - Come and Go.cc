#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Gi;

int n;
int m;
Gi grafo;
Vi visitado;

Gi grafo_rev;
Vi visitado_rev;

void DFS(int nodo)
{
	visitado[nodo]=1;
	for(int i=0;i<grafo[nodo].size();i++)
	{
		int otro_nodo=grafo[nodo][i];
		if(visitado[otro_nodo]!=1)
			DFS(otro_nodo);
	}
	
}
void DFS_rev(int nodo)
{
	visitado_rev[nodo]=1;
	for(int i=0;i<grafo_rev[nodo].size();i++)
	{
		int otro_nodo=grafo_rev[nodo][i];
		if(visitado_rev[otro_nodo]!=1)
			DFS_rev(otro_nodo);
	}
}

int main()
{
	int p,v,w;
	
	while(true)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)
			break;
		grafo=Gi(n);
		grafo_rev=Gi(n);
		visitado=Vi(n,0);
		visitado_rev=Vi(n,0);
	
		while(m--)
		{
			scanf("%d %d %d",&v,&w,&p);
			grafo[v-1].push_back(w-1);
			grafo_rev[w-1].push_back(v-1);
			if(p==2)
			{
				grafo[w-1].push_back(v-1);
				grafo_rev[v-1].push_back(w-1);	
			}
		}
		DFS(0);
		DFS_rev(0);
		
		bool cumple=true;
		for(int i=0;i<n;i++)
		{
			if(visitado[i]==0 || visitado_rev[i]==0) 
			{
				cumple=false;
				break;
			}
		}

		if(cumple) printf("1\n");
		else printf("0\n");

	}
	return 0;
}