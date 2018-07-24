#include <iostream>
#include <bitset>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

typedef int ll;

ll tamano_criba;
bitset<1003> bs;
vector<ll> primos;
vector<ll> res;
vector<int> borrar;
void criba(ll limite) // Calcula los números primos y los deposita en el vector "primos"
{
	tamano_criba = limite + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= tamano_criba; i++)
		if(bs[i])
		{
			for(ll j = i * i; j <= tamano_criba; j += i)
				bs[j] = 0;
			primos.push_back(i);
		}
}

void Llenar(list<int> &vec,int n)
{
	for(int i=0;i<=n;i++)
		vec.push_back(i);
}

void Responder(vector<int> vec)
{
	for(int i=1;i<vec.size();i++)
		if(vec[i]==i)
			res.push_back(i);
}
int main()
{
	criba(1000);
	vector<int> respuesta;
	
	list<int> ciudades;
	int n,c,t,aux;
	cin>>n;
	while(n--)
	{
		respuesta.clear();
		respuesta.push_back(0);
		ciudades.clear();
		res.clear();
		cin>>c;
		
		Llenar(ciudades,c);
		
		while(ciudades.size()>2)
		{
			borrar.clear();
			for(int i=0;i<primos.size();i++)
			{
				if(primos[i]>=ciudades.size())
					break;				
				std::list<int>::iterator it = ciudades.begin();
				std::advance(it, primos[i]);
				respuesta.push_back(*it);
				borrar.push_back(primos[i]);
			}
			for(int i=borrar.size()-1;i>=0;i--)
			{
				std::list<int>::iterator it = ciudades.begin();
				advance(it,borrar[i]);
				ciudades.erase(it);
			}
		}
		respuesta.push_back(1);
		Responder(respuesta);
		if(res.size())
		{
			for(int i=0;i<res.size()-1;i++)
				cout<<res[i]<<" ";
			cout<<res[res.size()-1]<<endl;
		}
		else if(c==1)
			cout<<"1"<<endl;
		else
			cout<<"-1"<<endl;
		cout<<endl;
	}

	return 0;
}
