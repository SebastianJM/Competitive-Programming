#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int fila,columna,test,c,f,max,aux;
	cin>>fila>>columna>>test;
	vector<vector<int> > matriz(fila+1,std::vector<int>(columna+1));
	vector<int> vec(fila+1,0);
	
	for(int i=1;i<=fila;i++)
	{
		aux=0;
		for(int e=1;e<=columna;e++)
		{
			cin>>matriz[i][e];
			if(matriz[i][e]==1)
				aux++;
			else
			{
				if(vec[i]<aux)
					vec[i]=aux;
				aux=0;
			}
		}
		if(vec[i]<aux)
			vec[i]=aux;
	}
	vec[0]=0;
	while(test--)
	{
		cin>>f>>c;
		if(matriz[f][c]==0)
			matriz[f][c]=1;	
		else	
			matriz[f][c]=0;
			
		aux=0;
		vec[f]=0;
		for(int i=1;i<=columna;i++)
		{
			if(matriz[f][i]==1)
				aux++;
			else
			{
				if(vec[f]<aux)
					vec[f]=aux;
				aux=0;
			}
		}
		if(vec[f]<aux)
			vec[f]=aux;
		max=*std::max_element(vec.begin(),vec.end());
		cout<<max<<endl;
	}	
	return 0;
}