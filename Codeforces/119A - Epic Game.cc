#include <iostream>

using namespace std;

int gcd(int a,int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
	int a,b,n,it(1);
	cin>>a>>b>>n;
	while(n)
	{
		if(it==1)
			n-=gcd(a,n);
		else
			n-=gcd(b,n);
		it*=-1;
	}
	if(it==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}