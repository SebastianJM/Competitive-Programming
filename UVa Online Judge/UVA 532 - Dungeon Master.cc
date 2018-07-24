#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef vector<bool> Vb;
typedef queue<int> Qu;

Gi grafo;
Vb visitado;
Qu cola;
Vi distancia;
char mapa[31][31];
int pos[31][31];

int main()
{
	int n,f,c,inicio,salida;
	char u,v;
	while(1)
	{
		scanf("%d %d %d",&n,&f,&c);
		if(n==0 && f==0 && c==0)
			return 0;
		int contador=0;
		grafo=Gi(n*f*c);
		visitado=Vb(n*f*c,false);
		distancia=Vi(n*f*c,-1);

		for(int i=0;i<f;i++)
		{
			for(int e=0;e<c;e++)
			{
				cin>>mapa[i][e];
				if(mapa[i][e]=='S')
					inicio=contador;
				else if(mapa[i][e]=='E')
					salida=contador;
				pos[i][e]=contador++;
			}
		}
		for(int i=0;i<f;i++)
		{
			for(int e=0;e<c;e++)
			{
				if(mapa[i][e]=='.'||mapa[i][e]=='S'||mapa[i][e]=='E')
				{
					if(i-1>=0 && (mapa[i-1][e]=='.'||mapa[i-1][e]=='S'||mapa[i-1][e]=='E'))
					{
						grafo[pos[i][e]].push_back(pos[i-1][e]);
					}
					if(i+1<f && (mapa[i+1][e]=='.'||mapa[i+1][e]=='S'||mapa[i+1][e]=='E'))
					{
						grafo[pos[i][e]].push_back(pos[i+1][e]);
					}
					if(e-1>=0 && (mapa[i][e-1]=='.'||mapa[i][e-1]=='S'||mapa[i][e-1]=='E'))
					{
						grafo[pos[i][e]].push_back(pos[i][e-1]);
					}
					if(e+1<c && (mapa[i][e+1]=='.'||mapa[i][e+1]=='S'||mapa[i][e+1]=='E'))
					{
						grafo[pos[i][e]].push_back(pos[i][e+1]);
					}			
				}
			}
		}
	
		//////////
		for(int k=1;k<n;k++)
		{
			for(int i=0;i<f;i++)
			{
				for(int e=0;e<c;e++)
				{
					cin>>u;
					if((u=='.' || u=='S' || u=='E'  )&& (mapa[i][e]=='.'||mapa[i][e]=='S'||mapa[i][e]=='E'))
					{
						grafo[contador].push_back(contador-f*c);
						grafo[contador-f*c].push_back(contador);
					}
					mapa[i][e]=u;
					if(mapa[i][e]=='S')
						inicio=contador;
					else if(mapa[i][e]=='E')
						salida=contador;
					pos[i][e]=contador++;
				}
			}
			for(int i=0;i<f;i++)
			{
				for(int e=0;e<c;e++)
				{
					if(mapa[i][e]=='.'||mapa[i][e]=='S'||mapa[i][e]=='E')
					{
						if(i-1>=0 && (mapa[i-1][e]=='.'||mapa[i-1][e]=='S'||mapa[i-1][e]=='E'))
						{
							grafo[pos[i][e]].push_back(pos[i-1][e]);

						}
						if(i+1<f && (mapa[i+1][e]=='.'||mapa[i+1][e]=='S'||mapa[i+1][e]=='E'))
						{
							grafo[pos[i][e]].push_back(pos[i+1][e]);
						}
						if(e-1>=0 && (mapa[i][e-1]=='.'||mapa[i][e-1]=='S'||mapa[i][e-1]=='E'))
						{
							grafo[pos[i][e]].push_back(pos[i][e-1]);
						}
						if(e+1<c && (mapa[i][e+1]=='.'||mapa[i][e+1]=='S'||mapa[i][e+1]=='E'))
						{
							grafo[pos[i][e]].push_back(pos[i][e+1]);
						}			
					}
				}
			}
		}

		int ini=inicio;
		cola.push(ini);
		distancia[ini]=0;
		visitado[ini]=true;

		while(!cola.empty())
		{
			int nodo=cola.front();
			cola.pop();
			for(int i=0;i<grafo[nodo].size();i++)
			{
				int otro_nodo=grafo[nodo][i];
				if(!visitado[otro_nodo])
				{
					visitado[otro_nodo]=true;
					cola.push(otro_nodo);
					distancia[otro_nodo]=distancia[nodo]+1;
				}
			}
		}
		if(distancia[salida]==-1)
			cout<<"Trapped!"<<endl;
		else
			cout<<"Escaped in "<<distancia[salida]<<" minute(s)."<<endl;
	}
	
	return 0;
}