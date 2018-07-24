#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tamano_criba;
bitset<1001> bs;
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

int main() 
{
	criba(1000);
	map<int,vector<int> > mp;
	cout<<primos[primos.size()-1]<<endl;
	vector<int> v(3);
	for(int i=0;i<primos.size();i++)
		for(int e=i;e<primos.size();e++)
			for(int k=e;k<primos.size();k++)
			{
				v[0]=primos[i];
				v[1]=primos[e];
				v[2]=primos[k];
				mp[v[0]+v[1]+v[2]]=v;
			}
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(mp.find(n)!=mp.end())
		{
			v=mp[n];
			cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
		}
		else
			cout<<0<<endl;
	}
	return 0;
}