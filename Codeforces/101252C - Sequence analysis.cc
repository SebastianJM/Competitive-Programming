#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

ll A,B,C;
ll f(ll x)
{
	return (A*x+x%B)%C; 
}
ll floydCycleFinding(ll x0)
{
	ll tortuga = f(x0), liebre = f(f(x0)), mu = 0, lambda = 1, c=1;
	while(tortuga != liebre) 
	{ 
		tortuga = f(tortuga); 
		liebre = f(f(liebre)); 
		c++;
		if(c>20000000)
			return -1;
	}
	liebre = x0;
	c=1;
	while(tortuga != liebre) 
	{ 
		tortuga = f(tortuga); 
		liebre = f(liebre); 
		mu++; 
		c++;
		if(c>20000000)
			return -1;
	}
	liebre = f(tortuga);
	while(tortuga != liebre) 
	{ 
		liebre = f(liebre); 
		lambda++; 
		c++;
		if(c>20000000)
			return -1;
	}
	return mu + lambda; // mu: id de inicio, lambda: extensión
}


int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>A>>B>>C;
	
	cout<<floydCycleFinding(1LL)<<endl;
	return 0;
}