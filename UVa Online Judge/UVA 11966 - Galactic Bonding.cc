#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<float,float> Pi;
typedef vector<Pi> Gi;

#define N 1000

Gi grafo;
Pi aux;
int root[N];
int num_stars;

void initSet()
{
	for(int i=0;i<grafo.size();i++)
	{
		root[i]=i;
		grafo[i]=Pi(0,0);
	}
}

int QF_FindSet(int a)
{
	/*if(root[a]!=a)
		return root[a]=QF_FindSet(root[a]);*/
	return root[a];
}

void QF_UnionSet(int a,int b)
{
	int rootA=QF_FindSet(a);
	int rootB=QF_FindSet(b);
	for(int i=0;i<num_stars;i++)
		if(root[i]==rootA)
			root[i]=rootB;
}

double distanciaMAX(int a,int b)
{
	return pow(grafo[a].first-grafo[b].first,2.0) + pow(grafo[a].second-grafo[b].second,2.0);
}

int countSets()
{
	int vecaux[N];
	int sets=0;
	for(int i=0;i<num_stars;i++)
		vecaux[i]=0;
	for(int i=0;i<num_stars;i++)
		vecaux[root[i]]++;
	for(int i=0;i<num_stars;i++)
		if(vecaux[i]>0)
			sets++;
	return sets;
}

int main()
{
	int test;
	float distancia;
	float x,y;
	scanf("%d",&test);
	int cont=0;
	while(cont<test)
	{
		scanf("%d %f",&num_stars,&distancia);
		grafo=Gi(num_stars);
		initSet();
		for(int i=0;i<num_stars;i++)
		{
			scanf("%f %f",&x,&y);
			grafo[i]=Pi(x,y);
		}

		for(int i=0;i<num_stars;i++)
		{
			for(int e=0;e<num_stars;e++)
			{
				if(e!=i && distanciaMAX(i,e)<=distancia*distancia)
					QF_UnionSet(e,i);
			}
		}
		printf("Case %d: %d\n",cont+1,countSets());
		cont++;
	}
	return 0;
}
