#include <stdio.h>

#define N 30000
int grafo[N];
int num_nodos;

void QF_InitSet()
{
	for(int i=1;i<=num_nodos;i++)
	{
		grafo[i]=i;
	}
}

int QF_FindSet(int elemento)
{
	return grafo[elemento];
}

void QF_UnionSet(int hijo,int padre)
{
	int root_hijo=QF_FindSet(hijo);
	int root_padre=QF_FindSet(padre);
	for(int i=1;i<=num_nodos;i++)
		if(grafo[i]==root_hijo)
			grafo[i]=root_padre;
}

int calcularMAX()
{
	int aux[N];
	for(int i=1;i<=num_nodos;i++)
		aux[i]=0;

	for(int i=1;i<=num_nodos;i++)
	{
		aux[grafo[i]]++;
	}

	int auxMax=0;

	for(int i=1;i<=num_nodos;i++)
	{
		if(aux[i]!=0 && auxMax<aux[i])
			auxMax=aux[i];
	}

	return auxMax;
}

int main()
{
	int test;
	int num_it;
	int o,d;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&num_nodos,&num_it);
		QF_InitSet();
		for(int i=0;i<num_it;i++)
		{
			scanf("%d %d",&o,&d);
			QF_UnionSet(o,d);
		}
		printf("%d\n",calcularMAX());
	}

	return 0;
}