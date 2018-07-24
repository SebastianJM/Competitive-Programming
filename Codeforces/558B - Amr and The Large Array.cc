#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxi 1000002

struct nodo
{
	int primero;
	int ultimo;
	int cantidad;
};

nodo vec[maxi];

int main()
{
	int n,aux;
	cin>>n;
	for(int i=0;i<maxi;i++)
	{
		vec[i].primero=maxi;
		vec[i].ultimo=-1;
		vec[i].cantidad=0;
	}
	int mayor=0;
	for(int i=0;i<n;i++)
	{
		cin>>aux;
		vec[aux].primero=min(i,vec[aux].primero);
		vec[aux].ultimo=max(i,vec[aux].ultimo);
		vec[aux].cantidad++;
		if(mayor<vec[aux].cantidad)
			mayor=vec[aux].cantidad;
	}
	int pri(0),ult(maxi);
	for(int i=0;i<maxi;i++)
	{
		if(vec[i].cantidad==mayor)
		{
			if(vec[i].ultimo-vec[i].primero<ult-pri)
			{
				ult=vec[i].ultimo;
				pri=vec[i].primero;
			}
		}
	}
	cout<<pri+1<<" "<<ult+1;

	return 0;
}