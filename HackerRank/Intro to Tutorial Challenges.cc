#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int v,tam,aux;
    scanf("%d",&v);
    scanf("%d",&tam);
	for(int i=0;i<tam;i++)
	{
		scanf("%d",&aux);
		if(aux==v)
		{
			printf("%d",i);
			return 1;
		}
	}
    return 0;
}