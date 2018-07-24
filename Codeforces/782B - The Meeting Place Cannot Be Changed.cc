#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-7

double pos[60003];
double vel[60003];
int n;
double f(double x)
{
	double ans=0.0,b;
	for(int i=0;i<n;i++)
	{
		b=1.0/vel[i];
		ans=max(ans,fabs(x-pos[i])*b);
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>pos[i];
	for(int i=0;i<n;i++)
		cin>>vel[i];

	double lo = 1.0, hi = 1000000000.0,mid1,mid2;
	while(lo + EPS < hi)
	{
		mid1 = (2.0*lo + hi) / 3.0;
		mid2 = (lo + 2.0*hi) / 3.0;
		if(f(mid1) < f(mid2)) // If f(mid1) is greater..(Change to "<" to minimize)
			hi = mid2; // Search in [lo, mid2]
		else // If f(mid2) is greater..
			lo = mid1; // Search in [mid1, hi]
	}

	double ans=0.0,b;
	for(int i=0;i<n;i++)
	{
		b=1.0/vel[i];
		ans=max(ans,((double)(abs(lo-pos[i])))*b);
	}
	printf("%.6f\n",ans);
}