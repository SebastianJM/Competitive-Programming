#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tamano_criba;
bitset<10000004> bs;
vector<ll> primos;
map<int,int> factores;
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

void factoresPrimos(ll N)
{
	ll idx = 0, PF = primos[idx];
	while(N != 1 && PF * PF <= N)
	{
		while(N % PF == 0)
		{
			N /= PF;
			factores[PF]++;
		}
		PF = primos[++idx];
	}
	if(N != 1)
		factores[N]++;
}
ll divisores(ll n)
{
    for(int i=1;i<sqrt(n);i++)
        if(n%i==0)
        {
            factoresPrimos(i);
            factoresPrimos(n/i);
        }
    int s=sqrt(n);
    if(s*s==n)
        factoresPrimos(s);
    ll ans=1;
	for(map<int,int>::iterator it=factores.begin();it!=factores.end();it++)
	    ans*=((*it).second+1);
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    criba(10000001);
    ll n;
    while(1)
    {
        cin>>n;
        if(!n)
            break;
        factores.clear();
        cout<<divisores(n)<<"\n";
    }
    return 0;
}