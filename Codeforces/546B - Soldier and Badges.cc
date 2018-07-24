#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,aux,total(0),max;
	cin>>n;
	vector<int> vec(n+1,0);
	vector<int> repetidos;
	vector<int> vacios;
	
	for(int i=0;i<n;i++)
	{
		cin>>aux;
		if(vec[aux]<1)
		
			vec[aux]++;
			
		
		else
			repetidos.push_back(aux);
	}
	for(int i=1;i<=n;i++)
	{
		if(vec[i]==0)
			vacios.push_back(i);
	}
	std::sort(repetidos.begin(),repetidos.end());
	std::sort(vacios.begin(),vacios.end());
	int bandera;
	int cond=1;
	max=n+1;
	for(int i=0;i<repetidos.size();i++)
	{
		bandera=0;
		if(cond)
		{
			for(int e=0;e<vacios.size();e++)
			{
				if(vacios[e]>repetidos[i])
				{
					total+=vacios[e]-repetidos[i];
					vacios[e]=0;
					bandera=1;
					break;
				}
			}
		}
		if(bandera==0)
		{
			cond=0;
			total+=max-repetidos[i];
			max++;
		}
	}
	cout<<total<<endl;

	return 0;
}