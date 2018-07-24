#include <iostream>

using namespace std;

int main()
{
	int a,b,a1,b1,a2,b2;
	cin>>a>>b>>a1>>b1>>a2>>b2;
	if((a1+a2<=a&&b1<=b&&b2<=b)||
		(a1+a2<=b&&b1<=a&&b2<=a)||
		(b1+b2<=a&&a1<=b&&a2<=b)||
		(b1+b2<=b&&a1<=a&&a2<=a)||
		(a1+b2<=a&&b1<=b&&a2<=b)||
		(a1+b2<=b&&b1<=a&&a2<=a)||
		(a2+b1<=a&&a1<=b&&b2<=b)||
		(a2+b1<=b&&a1<=a&&b2<=a))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;

}