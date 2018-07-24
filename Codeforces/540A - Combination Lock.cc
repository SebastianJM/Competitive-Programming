#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

char origen[1005];
char destino[1005];

int minimo(int i)
{
	return min(min(abs(origen[i]-destino[i]),abs(destino[i]-origen[i])),min(abs(origen[i]-48+58-destino[i]),abs(destino[i]-48+58-origen[i])));
}
int main() // 0 -> 48
{
	int n,total(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>origen[i];
	for(int i=0;i<n;i++)
	{
		cin>>destino[i];
		total+=minimo(i);
	}
	cout<<total;

	return 0;
}