#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;
#define N 5000010
ll tamano_criba; 
bitset<N+2> bs;
int pp[N];
int pa[N];

void criba(ll limite) // Calcula los números primos y los deposita en el vector "primos"
{
	int aux=0;
	tamano_criba = limite + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= tamano_criba; i++)
	{
		if(bs[i])
		{
			for(ll j = i * i; j <= tamano_criba; j += i)
				bs[j] = 0;
			
			aux++;
		}
		pp[i]=aux;
		
	}
}
void palindromizar(ll limite)
{
	int aux=0;
	ll temp,rem,reverse;
	for(ll i=1;i<=limite+1;i++)
	{
		 temp=i;
		 reverse=0;
		  while(temp!=0)
		  {
			 rem=temp%10;
			 reverse=reverse*10+rem;
			 temp/=10;
		  }  
		
		  if(reverse==i) 
		  {
			  aux++;
		  }
		  pa[i]=aux;
	}
}
int main()
{
	ll p,q;
	cin>>p>>q;
	pp[1]=0;
	criba(N);
	palindromizar(N);
	int max;
	for(int i=1;i<N-1;i++)
	{
		if(pp[i]*q<=p*pa[i])
		{
			max=i;
		}
	}
	cout<<max;

	return 0;
}