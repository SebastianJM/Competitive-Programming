#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi padreset;     // padre del nodo
vi tamset; // tamaño del set
vi candsp; // cuántos DSP hay en el set
vi costoset;    // costo del set

int dsp,ppp,r,budget,sum,u,v;
int dp[202][10001];

void init(int n) 
{
	tamset=vi(n,1);
	candsp=vi(n,0);
	for(int i=0;i<dsp;i++)
		candsp[i]++;
	padreset = vi(n, 0);           
	for(int i = 0; i < n; i++) 
		padreset[i] = i;            
}

int findSet(int i) 
{
	return (padreset[i] == i)? i : (padreset[i] = findSet(padreset[i])); 
}

bool isSameSet(int i, int j) 
{
	return findSet(i) == findSet(j); 
}

void unionSet(int i, int j) 
{
	if(!isSameSet(i, j)) 
	{
		//u=findSet(i);
		//=findSet(j);
		if(findSet(i)!=findSet(j))
			candsp[findSet(j)]+=candsp[findSet(i)];
		
		costoset[findSet(j)] += costoset[findSet(i)]; // El set j incrementa 
		tamset[findSet(j)]+=tamset[findSet(i)];
		padreset[findSet(i)] = findSet(j); // El set i tiene nuevo jefe
		
		
	}
}

int sizeOfSet(int i) 
{
	return costoset[findSet(i)];
}

int knapPPP()
{
	vector<int> pesos,valor;
	vector<bool> visitados(sum,false);
	for(int i=0;i<sum;i++)
	{
		u=findSet(i);
		if(!visitados[u])
		{
			visitados[u]=true;
			if(tamset[u]==1)
			{
				if(i>=dsp)
					pesos.push_back(0);
				else
					pesos.push_back(costoset[u]);
				valor.push_back(1);
			}
			else
			{
				pesos.push_back(0);
				valor.push_back(tamset[u]-candsp[u]);
				if(tamset[u]-candsp[u]<candsp[u])
				{
					pesos.push_back(costoset[u]);
					valor.push_back(candsp[u]-(tamset[u]-candsp[u]));
				}
			}
		}
	}
	for(int i=0;i<=budget;i++)
		dp[0][i]=0;
	for(int i=1;i<=pesos.size();i++)
		for(int e=0;e<=budget;e++)
			if(pesos[i-1]<=e)
				dp[i][e]=max(dp[i-1][e],dp[i-1][e-pesos[i-1]]+valor[i-1]);
			else
				dp[i][e]=dp[i-1][e];
	return dp[pesos.size()][budget];
}

int knapDSP()
{
	vector<int> pesos,valor;
	vector<bool> visitados(sum,false);
	for(int i=0;i<sum;i++)
	{
		u=findSet(i);
		if(!visitados[u])
		{
			visitados[u]=true;
			if(tamset[u]==1)
			{
				if(i<dsp)
					pesos.push_back(0);
				else
					pesos.push_back(costoset[u]);
				valor.push_back(1);
			}
			else
			{
				pesos.push_back(0);
				valor.push_back(candsp[u]);
				if(tamset[u]-candsp[u]>candsp[u])
				{
					pesos.push_back(costoset[u]);
					valor.push_back((tamset[u]-candsp[u])-candsp[u]);
				}
			}
		}
	}
	for(int i=0;i<=budget;i++)
		dp[0][i]=0;
	for(int i=1;i<=pesos.size();i++)
		for(int e=0;e<=budget;e++)
			if(pesos[i-1]<=e)
				dp[i][e]=max(dp[i-1][e],dp[i-1][e-pesos[i-1]]+valor[i-1]);
			else
				dp[i][e]=dp[i-1][e];
	return dp[pesos.size()][budget];
}
int main() 
{
	
	while(cin>>dsp>>ppp>>r>>budget)
	{
		sum=dsp+ppp;
		costoset = vi(sum);
		for(int i=0;i<sum;i++)
			cin>>costoset[i];
		init(sum);
		for(int i=0;i<r;i++)
		{
			cin>>u>>v;
			unionSet(u-1,v-1+dsp);
		}

		cout<<knapDSP()<<" "<<knapPPP()<<endl;
		
	}
	return 0;
}
