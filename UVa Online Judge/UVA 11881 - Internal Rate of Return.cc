#include <bits/stdc++.h>

using namespace std;
        
int n;
vector<int> cf;

double calculo(double mide)
{
	double dev=cf[0];
	for(int i=1;i<=n;i++)
		dev+=cf[i]/pow(1+mide,i);
	return dev;
}

int main()
{
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		cf=vector<int>(n+1);
		int maxx=0;
		bool muchos=false;
		for(int i=0;i<=n;i++)
		{
			cin>>cf[i];
			if(maxx<cf[i])
				maxx=cf[i];
		}
		int modo=calculo(0.0)>calculo(-0.999999)?1:0;
		double lo=-0.99999,hi=1000000.0,ans=0;
		while(hi-lo>0.00001f)
		{
			double mid=(lo+hi)/2.0f;
			double a=calculo(mid);
			if((modo && a>0.0) || (!modo && a<0.0))
				hi=mid;
			else
				lo=mid;
		}
		
		printf("%.2f\n",hi);
	}
	return 0;
}
