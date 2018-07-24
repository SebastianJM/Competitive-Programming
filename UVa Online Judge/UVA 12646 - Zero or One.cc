#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int a,b,c,n;
	while(cin>>a>>b>>c)
	{
		n=a+b+c;
		if(n==1)
		{
			if(a) cout<<"A\n";
			else if(b) cout<<"B\n";
			else cout<<"C\n";
		}
		else if(n==2)
		{
			if(!a) cout<<"A\n";
			else if(!b) cout<<"B\n";
			else cout<<"C\n";
		}
		else
			cout<<"*\n";
	}
	return 0;
}