#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;
ll tamano_criba;
bitset<5000010> bs;
vector<ll> primos;
void criba(ll limite)
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

vector<ll> factoresPrimos(ll N)
{
	vector<ll> factores;
	ll idx = 0, PF = primos[idx];
	while(N != 1 && PF * PF <= N) // Probar todos los primos <= sqrt(N)
	{
		while(N % PF == 0)
		{
			N /= PF;
			factores.push_back(PF);
		}
		PF = primos[++idx]; // Siguiente primo
	}
	if(N != 1)
		factores.push_back(N);
	return factores;
}

int main()
{
    long long n;
	vector<ll> aux;
	criba(5000000);
	while(1)
	{
		cin>>n;
		if(n==0)
			return 0;
		
		aux=factoresPrimos((n<0)?(-1*n):n);
		cout<<n<<" = ";
		if(n<0)
			cout<<"-1 x ";
		for(int i=0;i<aux.size();i++)
		{
			cout<<aux[i];
			if(i!=aux.size()-1)
				cout<<" x ";
		}
		cout<<endl;
	}
    return 0;
}
