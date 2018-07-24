#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> Pi;
typedef vector<int> Vi;
typedef pair<int,Pi> Pii;


Vi padres;

int num_nodos;
int num_relaciones;

void QF_InitSet()
{
	for(int i=0;i<padres.size();i++)
	{
		padres[i]=i;
	}
}

int QU_FindSetPathCompression(int a)
{
	if(padres[a]!=a)
		return padres[a]=QU_FindSetPathCompression(padres[a]);
	return a;
}

void QU_UnionSet(int a,int b)
{
	padres[QU_FindSetPathCompression(b)]=QU_FindSetPathCompression(a);
}

bool IsSameSet(int a,int b)
{
	return QU_FindSetPathCompression(a)==QU_FindSetPathCompression(b);
}

int main()
{
	int test;
	int u,v,peso;
	int menor;
	int cont=1;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&num_nodos,&num_relaciones);
		padres=Vi(num_nodos);
		priority_queue<Pii,vector<Pii>> heap;
		QF_InitSet();
		for(int i=0;i<num_relaciones;i++)
		{
			scanf("%d %d %d",&u,&v,&peso);
			heap.push(Pii(peso,Pi(u,v)));
		}
		Pii aux;
		for(int i=0;i<num_relaciones;i++)
		{
			aux=heap.top();
			heap.pop();
			if(!IsSameSet(aux.second.first,aux.second.second))
			{
				QU_UnionSet(aux.second.first,aux.second.second);
				menor=aux.first;
			}
		}

		printf("Case #%d: %d\n",cont,menor);
		cont++;
	}
	return 0;
}

