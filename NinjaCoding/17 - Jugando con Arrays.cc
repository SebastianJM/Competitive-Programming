#include <iostream>
#include <stdio.h>

using namespace std;

int vec[10005];
struct orden
{
	int min;
	int max;
	int can;
};

orden ordenes[10005];

inline void Sumar(int min,int max,int can)
{
	for(int i=min;i<=max;i++)
		vec[i]+=can;
}
int main()
{
	int num,ord,veces,desde,hasta;
	while(cin>>num>>ord>>veces)
	{
		for(int i=0;i<num;i++)
			scanf("%d",&vec[i]);

		for(int i=0;i<ord;i++)
			scanf("%d %d %d",&ordenes[i].min,&ordenes[i].max,&ordenes[i].can);

		for(int i=0;i<veces;i++)
		{
			scanf("%d %d",&desde,&hasta);
			for(int e=desde-1;e<=hasta-1;e++)
				Sumar(ordenes[e].min-1,ordenes[e].max-1,ordenes[e].can);		
		}
		for(int i=0;i<num;i++)
		{
			printf("%d",vec[i]);
			if(i!=num-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
