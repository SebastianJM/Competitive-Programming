#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool esImpar(long long a)
{
	return a%2==1;
}
int main()
{
	long long a,b,s;
	cin>>a>>b>>s;
	a=abs(a)+abs(b);

	if(s< a || (esImpar(s) && !esImpar(a)) || (!esImpar(s) && esImpar(a)))
		cout<<"No";
	else
		cout<<"Yes";
	
	return 0;
}
