#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

typedef pair<int, int> Pi;
typedef pair<int, Pi> Pii;

//UFDS

vector<int> ufds_padres;

void initSet(int n)
{
	ufds_padres = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		ufds_padres[i] = i;
	}
}

int findSet(int elemento)
{
	return ufds_padres[elemento] == elemento ? elemento : 
		ufds_padres[elemento] = findSet(ufds_padres[elemento]);
}

bool isSameSet(int elementoA, int elementoB)
{
	return findSet(ufds_padres[elementoA]) == findSet(ufds_padres[elementoB]);
}

void unionSet(int elementoA, int elementoB)
{
	ufds_padres[findSet(elementoA)] = findSet(elementoB);
}

int main()
{
	int n, r, u, v, w;
	while(true)
	{
		priority_queue<Pii, vector<Pii>,greater<Pii>> pq;
		priority_queue<int, vector<int>,greater<int>> enteros;

		scanf("%d %d", &n, &r);
		if(n==0 && r==0)
			break;

		initSet(n);

		for (int i = 0; i < r; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			pq.push(Pii(w,Pi(u,v)));
		}

		int cont_aristas = 0;

		while(!pq.empty())
		{
			Pii aux = pq.top(); pq.pop();
		
			if(!isSameSet(aux.second.first, aux.second.second))
			{
				cont_aristas++;
				unionSet(aux.second.first, aux.second.second);
			}
			else
				enteros.push(aux.first);
		}
		int num=enteros.size()-1;
		if(enteros.empty())
			printf("forest");
		else
		{
			while(!enteros.empty())
			{
				printf("%d", enteros.top());
				enteros.pop();
				if(num!=0)
				{
					printf(" ");
					num--;
				}
			}	
		}
		printf("\n");
	}

	return 0;
}