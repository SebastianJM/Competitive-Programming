#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

// Devuelve gcd(a,b) seguido del par (x,y) que cumple: ax + by = gcd(a,b)
iii extendedEuclid(int a, int b)
{
	if(b == 0)
		return iii(a, ii(1, 0)); // Caso base: Residuo 0
	iii p = extendedEuclid(b, a % b); // Logica del algoritmo de Euclides
	int x = p.second.first, y = p.second.second;
	return iii(p.first, ii(y, x - (a / b) * y));
}

int main()
{
	int a,b;
	iii aux;
	while(cin>>a>>b)
	{
		aux=extendedEuclid(a,b);
		cout<<aux.second.first<<" "<<aux.second.second<<" "<<aux.first<<endl;
	}
    return 0;
}
