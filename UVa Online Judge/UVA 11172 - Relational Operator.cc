#include <stdio.h>

int main()
{
	int test,a,b;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&a,&b);
		if(a<b)
			printf("<\n");
		else if(a>b)
			printf(">\n");
		else if(a==b)
			printf("=\n");
	}
	return 0;
}