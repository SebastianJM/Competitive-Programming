#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,n,total;
	scanf("%lf %lf %lf",&a,&b,&n);	
	printf("%.0lf",ceil((a/n)) * ceil((b/n)));
    return 0;
}

