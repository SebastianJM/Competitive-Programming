#include <bits/stdc++.h>
using namespace std;

int main() 
{
	double ans=100000000,xi,yi,xx,yy,v;
	int q;
	cin>>xi>>yi>>q;
	for(int i=0;i<q;i++)
	{
		cin>>xx>>yy>>v;
		ans=min(ans,sqrt(pow(xi-xx,2)+pow(yi-yy,2))/v);
	}
	printf("%.8lf",ans);
	return 0;
}