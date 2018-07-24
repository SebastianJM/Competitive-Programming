#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t;
	double s,v;
	cin>>t;
	while(t--)
	{
		cin>>s>>v;
	
		printf("%.6lf\n", (2.0/3.0)*(s/v));
	}
	return 0;
} 