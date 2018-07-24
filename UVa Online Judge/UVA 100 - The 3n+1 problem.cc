#include <stdio.h>

int algoritmo(int n)
{
	int rep=1;
	while(n!=1)
	{
		if(n%2==1)
			n=3*n+1;
		else 
			n/=2;
		rep++;
	}
	return rep;
}

#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

int main()
{
	int x,z,max;
	
	while(scanf("%d %d",&x,&z)==2)
	{
		max=0;
		for(int i=MIN(x,z);i<=MAX(x,z);i++)
		{
			int fun=algoritmo(i);
			max=(max<fun) ? fun : max;
		}
		printf("%d %d %d\n",x,z,max);
	}
	return 0;
}