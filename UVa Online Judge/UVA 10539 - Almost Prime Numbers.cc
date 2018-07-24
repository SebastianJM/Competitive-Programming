#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tamano_criba;
bitset<1000010> bs;
vector<ll> primos;
vector<ll> almost;

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
	for(int i=0;i<primos.size();i++)
	{
		ll a=primos[i];
		while(a<=1000000000000/primos[i])
		{
			a*=primos[i];
			almost.push_back(a);
		}
	}
	sort(almost.begin(),almost.end());
}
int solve(ll left,ll right)
{
	int ans=upper_bound(almost.begin(),almost.end(),right)-almost.begin();
	return ans-(lower_bound(almost.begin(),almost.end(),left)-almost.begin());
}
int main() 
{
	criba(1000001);
	ll t,l,r;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		cout<<solve(l,r)<<endl;
	}
	return 0;
}