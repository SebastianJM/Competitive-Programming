#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

double L,n,c,radio,S;

double calculo(double ang)
{
	radio=(L/2)/sin(ang);
	return radio*ang*2;
}

int main()
{
	while(1)
	{
		cin>>L>>n>>c;
		if(L<0 && n<0 && c<0)
			break;
		S=(1+n*c)*L;
		double lo=0,hi=PI/2,mid;
		for(int i=0;i<50;i++)
		{
			mid=(hi+lo)/2;
			double a=calculo(mid);
			if(a<S)
				lo=mid;
			else
				hi=mid;
		}
		double h=radio*(1-cos(mid));
		printf("%.3lf\n",h);
		
	}
	return 0;
}