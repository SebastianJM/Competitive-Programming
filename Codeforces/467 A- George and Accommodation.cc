#include <iostream>

using namespace std;

int main()
{
	int n,a,b,r(0);
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(b-a>=2)
			r++;
	}
	cout<<r;
	return 0;
}
