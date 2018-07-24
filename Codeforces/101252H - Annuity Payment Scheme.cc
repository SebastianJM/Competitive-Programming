#include <bits/stdc++.h>
using namespace std;

double s,p;
int m;
bool cumple(double x)
{
	double con=0.0,b=0.0,a=0.0;
	for(int i=0;i<m;i++)
	{
		a=(s-con)*p/100;
		b=x-a;
		con+=b;
	}
	if(con>s)
		return true;
	return false;
}
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>s>>m>>p;
	double lo = 0.0, hi = 10000000.0, ans;
	for(int k = 0; k < 60; k++) // Fixed iterations to avoid an infinite loop..
	{
		double mid = (lo + hi) * 0.5; // Find middle element
		if(cumple(mid)) // If mid is a valid answer..
			ans = hi = mid; // Search in: [lo, mid]. Save the answer
		else // If mid is not a valid answer..
			lo = mid; // Search in: [mid, hi]
	}
	printf("%.6lf\n",ans);	
	return 0;
}