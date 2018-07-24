#include <bits/stdc++.h>

#define PI atan(1)*4
#define g 9.8
using namespace std;

double x,y,c,a,dis;
vector<pair<double,double> > edif;
bool valido(double angulo)
{
	double H=(tan(angulo)*dis)/4;
	double V=sqrt((H*2*g)/(sin(angulo)*sin(angulo)));
	double vx=V*cos(angulo);

	for(int i=0;i<edif.size()-1;i++)
	{
		double t=edif[i].second/vx;
		if(V*sin(angulo)*t-g*t*t/2<edif[i].first)
			return false;
	}
	return true;
}
int main()
{
	int n;

	while(cin>>n)
	{
		dis=0;
		edif=vector<pair<double,double> >();
		for(int i=0;i<n;i++)
		{
			cin>>y>>x;
			edif.push_back(pair<double,double>(y,dis));
			dis+=x;
			edif.push_back(pair<double,double>(y,dis));
		}
		double lo = 0, hi =90, ans = -1;
		while(fabs(hi-lo)>1e-7)
		{
		  double mid = lo + (hi-lo)/2; 
		  if(valido(mid*PI/180))
			 ans = hi=mid;  	
		  else
			  lo = mid;
		}
		double Hh=(tan(ans*PI/180)*dis)/4;
		double Vv=sqrt((Hh*2*g)/(sin(ans*PI/180)*sin(ans*PI/180)));
		printf("%.2f %.2f\n",ans,Vv);
	}
	return 0;
}