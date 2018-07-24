#include <stdio.h>

int main()
{
	int test,x,y;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&x,&y);
		x=x-2;
		y=y-2;
		while(x%3!=0)
			x++;
		x=x/3;
		while(y%3!=0)
			y++;
		y=y/3;
		printf("%d\n",x*y);
	}
	return 0;
}