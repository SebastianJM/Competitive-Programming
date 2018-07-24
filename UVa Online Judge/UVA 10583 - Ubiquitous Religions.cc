#include <stdio.h>

int padres[50000];
int num_nodos;
int num_relaciones;
int religiones;

void InitSet()
{
	for(int i=0;i<num_nodos;i++)
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
	int u,v,test;
	test=1;
	while(true)
	{
		scanf("%d %d",&num_nodos,&num_relaciones);
		if(num_nodos==0 && num_nodos==num_relaciones)
			break;
		InitSet();
		religiones=num_nodos;
		for(int i=0;i<num_relaciones;i++)
		{
			scanf("%d %d",&u,&v);
			if(!IsSameSet(u-1,v-1))
				num_nodos--;
			QU_UnionSet(u-1,v-1);
		}
		printf("Case %d: %d\n",test,num_nodos);
		test++;
	}
	return 0;
}
	