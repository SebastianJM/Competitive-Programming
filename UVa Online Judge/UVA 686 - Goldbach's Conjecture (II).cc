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
	criba(5000000);
	int n,res;
	while(1)
	{
		cin>>n;
		if(n==0)
			return 0;
		res=0;
		for(int i=0;i<n-1;i++)	
			for(int e=i;e<n-1;e++)
			{
				if(primos[i]+primos[e]>n)
					break;
				else if(primos[i]+primos[e]==n)
					res++;
			}
		cout<<res<<endl;		
	}
    return 0;
}
