#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;
ll tamano_criba;
bitset<5000010> bs;
vector<ll> primos;
vector<ll> magics;
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
	int n,a,p;
	ll aux=30;
	cin>>n;
	criba(30000);
	while(magics.size()<1000)
	{
		p=0;
		vector<ll> au=factoresPrimos(aux);
		for(int i=1;i<au.size();i++)
			if(au[i]!=au[i-1])
				p++;
		if(p>=2)
			magics.push_back(aux);
		aux++;
	}
	while(n--)
	{
		cin>>a;
		cout<<magics[a-1]<<endl;
	}
	return 0;
}
