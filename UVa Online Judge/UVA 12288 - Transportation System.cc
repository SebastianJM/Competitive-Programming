#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>

using namespace std;

typedef pair<int,int> Pi;
typedef vector<int> Vi;
typedef pair<float,Pi> Pii;



Vi padres;
Vi x;
Vi y;

int num_nodos;
int peso_max;

void InitSet()
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
	double road,rail;
	int num_paises;
	int u,v;
	double peso;
	int contador=1;
	
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&num_nodos,&peso_max);
		road=rail=0;
		num_paises=1;
		
		padres=Vi(num_nodos);
		x=y=Vi(num_nodos);
		InitSet();
		priority_queue<Pii,vector<Pii>,greater<Pii>> heap;
		for(int i=0;i<num_nodos;i++)
		{
			scanf("%d %d",&u,&v);
			x[i]=u;
			y[i]=v;
		}
	
		for(int i=0;i<num_nodos-1;i++)
		{
			for(int e=i+1;e<num_nodos;e++)
			{
				peso=pow(x[i]-x[e],2);
				peso+=pow(y[i]-y[e],2);
				heap.push(Pii(peso,Pi(i,e)));
			}
		}
		int cont=0;
		Pii aux;
		while(cont!=num_nodos-1)
		{
			aux=heap.top();
			heap.pop();
			if(!IsSameSet(aux.second.first,aux.second.second))
			{
				QU_UnionSet(aux.second.first,aux.second.second);
				if(aux.first>peso_max*peso_max)
				{
					num_paises++;
					rail+=(double)sqrt(aux.first);
				}
				else
					road+=(double)sqrt(aux.first);
				cont++;
			}
		}
		double sumx,sumy;
		sumx=road;
		sumy=rail;

		if(road>=(int)sumx+0.5)
			sumx=1;
		else
			sumx=0;

		if(rail>=(int)sumy+0.5)
			sumy=1;
		else
			sumy=0;

		printf("Case #%d: %d %d %d\n",contador,num_paises,(int)road+(int)sumx,(int)rail+(int)sumy);
		contador++;
	}
	return 0;
}


