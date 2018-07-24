#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<int> Vi;

Vi padres;
Vi visitado;
Vi size;
Vi peso;
int num_nodos;

void QU_InitSet()
{
	for(int i;i<padres.size();i++)
	{
		size[i]=1;
		visitado[i]=1;
		padres[i]=i;
	}
}

int QU_FindSetPathCompression(int a)
{
	if(padres[a]!=a)
		return padres[a]=QU_FindSetPathCompression(padres[a]);
	return a;
}

void QU_WeightedUnionSet(int a,int b)
{
	int rootA=QU_FindSetPathCompression(a);
	int rootB=QU_FindSetPathCompression(b);

	if(size[rootA]>size[rootB])
	{
		size[rootA]+=size[rootB];
		padres[rootB]=rootA;
	}
	else
	{
		size[rootB]+=size[rootA];
		padres[rootA]=rootB;
	}
}

bool QU_IsSameSet(int a,int b)
{
	return QU_FindSetPathCompression(a)==QU_FindSetPathCompression(b);
}

bool calcular()
{
	int aux;
	int total=0;
	for(int i=0;i<num_nodos;i++)
	{
		if(visitado[i]!=0)
		{
			aux=QU_FindSetPathCompression(i);
			for(int e=0;e<num_nodos;e++)
			{
				if(QU_FindSetPathCompression(e)==aux)
				{
					visitado[e]=0;
					total+=peso[e];
				}
 			}
			if(total!=0)
				return false;
		}
	}
	return true;
}		

int main()
{
	int test;
	int num_relaciones;
	int w,x,y;
	scanf("%d",&test);
	while(test--)
	{
		
		scanf("%d %d",&num_nodos,&num_relaciones);
		padres=Vi(num_nodos);
		size=Vi(num_nodos);
		visitado=Vi(num_nodos);
		peso=Vi(num_nodos);
		QU_InitSet();

		for(int i=0;i<num_nodos;i++)
		{
			scanf("%d",&w);
			peso[i]=w;
		}

		for(int i=0;i<num_relaciones;i++)
		{
			scanf("%d %d",&x,&y);
			QU_WeightedUnionSet(x,y);
		}
		if(calcular())
			printf("POSSIBLE\n");
		else 
			printf("IMPOSSIBLE\n");
	}
	return 0;		
}