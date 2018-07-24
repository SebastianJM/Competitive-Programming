#include <bits/stdc++.h>
using namespace std;

int main() 
{
	// Media aritmética - Media geométrica - Inequality
	double k=1,s,p,last=0.0,act;
	cin>>s>>p;
	if(s==p)
	{
		cout<<1<<endl;
		return 0;
	}
	if(s>p)
	{
		cout<<2<<endl;
		return 0;
	}
	act=pow(s/k,k);
	while(act<p)
	{
		last=act;
		k++;
		act=pow(s/k,k);
		if(act<last)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<k<<endl;
	return 0;
}