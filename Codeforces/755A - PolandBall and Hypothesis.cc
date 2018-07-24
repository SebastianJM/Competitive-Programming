#include <bits/stdc++.h>

using namespace std;

typedef double ll;
ll tamano_criba;
bitset<1000009> bs;
vector<ll> primos;
void criba(long long limite)
{
	tamano_criba = limite + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(long long i = 2; i <= tamano_criba; i++)
		if(bs[i])
		{
			for(long long j = i * i; j <= tamano_criba; j += i)
				bs[j] = 0;
			primos.push_back((double)i);
		}
}

int main() 
{
	criba(1000009);
	double n;
	cin>>n;

	for(double i=1;i<1004.00;i+=1.00)	
		if(find(primos.begin(),primos.end(),n*i+1.00)==primos.end())
		{
			cout<<(int)i<<endl;
			break;
		}
	
	return 0;
}