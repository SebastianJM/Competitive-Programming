#include <bits/stdc++.h>

using namespace std;
double x,y,c,a;

double valor(double w)
{
	return (sqrt(y*y-w*w)*sqrt(x*x-w*w))/(sqrt(x*x-w*w)+sqrt(y*y-w*w));
}
int main()
{
	while(cin>>x>>y>>c)
	{

		double lo = 0, hi =x>y?y:x, ans = -1;
		for(int k = 0; k < 50; k++)
		{
		  double mid = lo + (hi-lo)/2; 
		  a=valor(mid);
		  if(a>=c-0.0000001 && a<=c+0.0000001)
		  {
			 ans = mid;  
			 break;
		  }
		  else if(a<c)
			  hi=mid;
		  else
			  lo = mid;
		}
		printf("%.3f\n",ans);
	}
	return 0;
}