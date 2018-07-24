#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0.0)
#define EPS 1e-9

int comparar(double d1, double d2) 
{    
	if(d2 - d1 > EPS)
		return -1; // d2 > d1    
	if(d1 - d2 > EPS) 
		return 1;  // d1 > d2 
	return 0;                    // d1 == d2 
} 

double c2area(double x1,double x2,double r){
    	double rx1=x1,ry1=0.0,rx2=x2,ry2=0.0;
    	double drma=sqrt((rx1-rx2)*(rx1-rx2)+(ry1-ry2)*(ry1-ry2));
    	double a1=acos((r*r+drma*drma-r*r)/(2.0*r*drma));
    	double a2=acos((r*r+drma*drma-r*r)/(2.0*r*drma));
    	double res=(a1*r*r+a2*r*r-r*drma*sin(a1));
    	return res;
}

int main() 
{
	int n;
	double r,x,a,b,area;
	double ans=0.0;
	scanf("%d%lf",&n,&r);
	vector<double> xx(n);
	
	area=PI*r*r;
	ans=area*n;
	for(int i=0;i<n;i++)
		cin>>xx[i];
	sort(xx.begin(),xx.end());
	
	for(int i=1;i<n;i++)
	{
		if(xx[i]-xx[i-1]<2*r)
			ans-=c2area(xx[i-1],xx[i],r);
	}
	printf("%.10f\n",ans);
	return 0;
}