#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> Vi;
typedef vector<char> Vc;
Vc vec;

int main()
{
	int test;
	int cont=0;
	int espanta;
	int num_nodos;
	scanf("%d",&test);
	while(cont<test)
	{
		espanta=0;
		scanf("%d",&num_nodos);
		vec=Vc(num_nodos+2,'#');
		for(int i=0;i<num_nodos;i++)
			scanf(" %c",&vec[i]);
	
		for(int i=0;i<num_nodos;i++)
		{
			if(vec[i]=='.')
			{
				vec[i]=vec[i+1]=vec[i+2]='#';
				espanta++;
			}
		}
		printf("Case %d: %d\n",cont+1,espanta);
		cont++;
	}
	return 0;
}