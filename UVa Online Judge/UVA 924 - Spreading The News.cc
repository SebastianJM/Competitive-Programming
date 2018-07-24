#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef vector<bool> Vb;
typedef queue<int> Qu;

Vi distancia;
Gi grafo;
Vb visitado;
Vi resultados;
Qu cola;

int main()
{
	int u,n,m;
	scanf("%d",&n);
	grafo=Gi(n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(int e=0;e<m;e++)
		{
			scanf("%d",&u);
			grafo[i].push_back(u);
		}
	}

	int test,inicio;
	scanf("%d",&test);
	while(test--)
	{
		int max=0;
		int maxDay,maxBoom;
		maxDay=maxBoom=0;
		visitado=Vb(n,false);
		distancia=Vi(n,-1);

		scanf("%d",&inicio);
		cola.push(inicio);
		distancia[inicio]=0;
		visitado[inicio]=true;
		
		while(!cola.empty())
		{
			int nodo=cola.front();
			cola.pop();
			for(int i=0;i<grafo[nodo].size();i++)
			{
				if(!visitado[grafo[nodo][i]])
				{
					cola.push(grafo[nodo][i]);
					visitado[grafo[nodo][i]]=true;
					distancia[grafo[nodo][i]]=distancia[nodo]+1;
					max=distancia[grafo[nodo][i]]+1;
				}
			}
		}

		if(max==0)
		{
			printf("0\n");
			continue;
		}
		resultados=Vi(max,0);

		for(int i=0;i<n;i++)
		{
			if(distancia[i]>=0)
				resultados[distancia[i]]++;
		}

		for(int i=1;i<max;i++)
		{
			if(resultados[i]>maxBoom)
			{
				maxBoom=resultados[i];
				maxDay=i;
			}
		}

		printf("%d %d\n",maxBoom,maxDay);
	}

	return 0;
}
	
/// OTRA FORMA	


#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	vector<vector<int>> emp;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		emp.push_back(vector<int>(a));
		for (int e = 0; e < a; e++)
			cin >> emp[i][e];
	}
	cin >> a;
	for (int i=0; i < a; i++)
	{
		vector<vector<int>> aux=emp;
		cin >> b;
		int can = 3,maxi=0,maxdia,dia=1;
		vector<int> por_visi(1, b);	
		vector<int> visitados(n, 0);
		visitados[b] = 1;
		while (por_visi.size()>0)
		{
			int amaxi = 0;
			vector<int> nuevo_visi;
			can = 0;
			for (int e = 0; e < por_visi.size(); e++)
			{
				for (int k = 0; k < aux[por_visi[e]].size(); k++)
				{
					if (!visitados[aux[por_visi[e]][k]])
					{
						visitados[aux[por_visi[e]][k]] = 1;
						can++;
						nuevo_visi.push_back(aux[por_visi[e]][k]);
					}
				}
			}
			if (can > maxi)
			{
				maxi = can;
				maxdia = dia;
			}
			por_visi = nuevo_visi;
			dia++;
		}
		if (maxi>0)
			cout << maxi << " " << maxdia << endl;
		else
			cout << 0 << endl;
	}
	

	return 0;
}
