#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;

ll tamano_criba;
bitset<5000010> bs;
vector<ll> primos;

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

int main()
{
	long long n;
	cin>>n;
	criba(n);
	int ans(0),aux;
	for(int i=1;i<=n;i++)
	{
		aux=0;
		for(int e=0;e<primos.size();e++)
		{
			if(primos[e]>i)
				break;
			if(i%primos[e]==0)
				aux++;			
		}
		if(aux==2)
			ans++;
	}
	cout<<ans;
	return 0;	
}
