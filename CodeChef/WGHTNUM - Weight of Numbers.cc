#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
 
ull modU(ull p, ull n, ull MOD)
{
	if(p == 0ULL)      return 1ULL; 
		ull q = modU(p/2LL, n, MOD); 
	if(p % 2ULL == 0ULL)      return (q*q) % MOD; 
		else      return (((q*n) % MOD) * q) % MOD; 
}
int main() 
{
	unsigned long long mod=1000000007,n;
	int t,w;
	cin>>t;
	while(t--)
	{
		cin>>n>>w;
		int a=abs(w);
		if(a>9)
			cout<<0<<endl;
		else
		{
			ull num=9-a;
			if(w<0)
				num++;
			cout<<(modU(n-2ULL,10,mod)*num)%mod<<endl;
		}
	}
	
	return 0;
} 