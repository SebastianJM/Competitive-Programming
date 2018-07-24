#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef vector<bool> Vb;
typedef stack<int> St;

Gi grafo;
Vb visitado;
St orden_finalizacion;

void DFS(int nodo)
{
	visitado[nodo]=true;
	for(int i=0;i<grafo[nodo].size();i++)
	{
		if(!visitado[grafo[nodo][i]])
			DFS(grafo[nodo][i]);
	}
	orden_finalizacion.push(nodo);
}

int main()
{
	int n,m;
	int u,v;
	while(true)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)
			break;

		grafo=Gi(n);
		visitado=Vb(n,false);

		while(m--)
		{
			scanf("%d %d",&v,&u);
			grafo[v-1].push_back(u-1);
		}

		for(int i=0;i<n;i++)
		{
			if(!visitado[i])
				DFS(i);
		}
		while(!orden_finalizacion.empty())
		{
			printf("%d ",orden_finalizacion.top()+1);
			orden_finalizacion.pop();
		}
	}
	
	return 0;
}