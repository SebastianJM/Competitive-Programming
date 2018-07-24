#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int n,a,b;
	vector<double> v;
	cin>>n>>a>>b;
	v=vector<double>(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.rbegin(),v.rend());
	double a_a=0.0,a_b=0.0,ans=0.0;
	for(int i=0;i<a;i++)
		a_a+=v[i];
	for(int i=a;i<a+b;i++)
		a_b+=v[i];
	ans=a_a/a+a_b/b;
	a_a=a_b=0.0;
	for(int i=0;i<b;i++)
		a_b+=v[i];
	for(int i=b;i<a+b;i++)
		a_a+=v[i];
	ans=max(ans,a_a/a+a_b/b);
	printf("%.8f\n",ans);
	return 0;
}