#include <iostream>
#include <stdio.h>


using namespace std;

int main()
{
	int x,r(0);
	cin>>x;
	while(x>0)
	{
		if(x&1)
			r++;
		x>>=1;
	}
	cout<<r;
	return 0;
}