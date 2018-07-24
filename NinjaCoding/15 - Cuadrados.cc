#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n,a,r;
	cin>>n;
	while(n--)
	{
		cin>>a;
		r=0;
		for(int i=1;i<=a;i++)
			r+=pow(i,2);
		cout<<r<<endl;
	}
	return 0;
}

