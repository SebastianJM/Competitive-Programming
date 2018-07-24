#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tamano_criba;
bitset<5005> bs;
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
	criba(5000);
	int n,a;
	cin>>n>>a;

	for(int e=1;e<primos.size();e++)
	{
		if(primos[e]>n)
			break;
		for(int i=1;i<primos.size();i++)
		{
			if(primos[i]+primos[i-1]+1==primos[e])
				a--;
			else if(primos[i]+primos[i-1]+1>primos[e])
				break;
		}
	}
                
	if(a<=0)
		cout<<"YES";
	else
		cout<<"NO";
    return 0;
}
