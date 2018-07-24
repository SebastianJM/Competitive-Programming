#include <bits/stdc++.h>

using namespace std;
        
int a,b;
double alto;

double calculo(double largo)
{
	alto=(largo*b)/a;
	double radio=sqrt((largo/2)*(largo/2)+(alto/2)*(alto/2));
	double angulo=2*acos((largo/2)/radio);
	double s=radio*angulo;
	return 2*largo+2*s;
}

int main()
{
	int t=1;
	char puntos;
	while(cin>>a>>puntos>>b)
	{
		double lo=0,hi=300,ans=-1;
		while(lo<hi)
		{
			double mid=(hi+lo)/2;
			double a=calculo(mid);
			if(a>=400.0-0.00000000001 && a<=400.0+0.00000000001)
			{
				ans=mid;
				break;
			}
			else if(a>400)
				hi=mid;
			else
				lo=mid;
		}
		cout<<"Case "<<t++<<": ";
		printf("%.10f %.10f\n",ans,alto);
	}
	return 0;
}
