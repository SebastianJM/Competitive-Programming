#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tamano_criba;
bitset<10005> bs;
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
	criba(10000);
	int n,a;
	cin>>n;
	while(n--)
	{
		cin>>a;
		for(int i=0;i<primos.size();i++)
		{
			if(primos[i]<=a && primos[i]*2>a)
			{
				cout<<primos[i]<<endl;
				break;
			}
		}
	}

    return 0;
}
