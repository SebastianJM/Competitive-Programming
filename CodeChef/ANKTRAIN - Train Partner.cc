#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string v[9];
	int val[9];
	v[0]="SL"; val[0]=-1;
	v[1]="LB"; val[1]=3;
	v[2]="MB"; val[2]=3;
	v[3]="UB"; val[3]=3;
	v[4]="LB"; val[4]=-3;
	v[5]="MB"; val[5]=-3;
	v[6]="UB"; val[6]=-3;
	v[7]="SU"; val[7]=1;
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<n+val[n%8]<<v[n%8]<<endl;
	}
	return 0;
} 