#include <stdio.h>
#include <math.h>

using namespace std;

int main() 
{
	int n;
	double ax, ay, bx, by,cx,cy,dx,dy;
	scanf("%d", &n);

	while(n--) 
	{
		scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
		cx = -bx;
		cy = by;
		dx = ax;
		dy = -ay;
		
		printf("%.3lf\n",sqrt(powl(ax-bx,2)+powl(ay-by,2))+sqrt(powl(cx-dx,2)+powl(cy-dy,2)));
	}
    return 0;
}