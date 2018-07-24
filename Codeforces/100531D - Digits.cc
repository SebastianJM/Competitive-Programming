#include <bits/stdc++.h>
using namespace std;
const int MAX= 2000000;
int main() 
{
	freopen("digits.in","r",stdin);
	freopen("digits.out","w",stdout);
	unsigned long long suma[1000],s,ans=ULLONG_MAX;
	int cont[1000],n,x;
	memset(suma,0,sizeof suma);
	memset(cont,0,sizeof cont);
	cin>>n;
	if(n==1)
		cout<<1<<"\n";
	else
	{
		for(int i=0;i<MAX;i++)
	{
		x=i;
		s=0;
		while(x)
		{
			s+=(x%10);
			x/=10;
		}
		suma[s]+=i;
		cont[s]++;
		if(cont[s]==n)
		{
			ans=min(suma[s],ans);
		}
			
	}
	cout<<ans<<"\n";
	}
	
	
	return 0;
}