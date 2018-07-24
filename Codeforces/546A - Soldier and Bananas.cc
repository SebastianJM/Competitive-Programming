#include <iostream>

using namespace std;
int main()
{
	int k,t,n;
	int suma(0);
	cin>>k>>t>>n;
	for(int i=1;i<=n;i++)
		suma+=k*i;

	if(suma>t)
		cout<<suma-t<<endl;
	else
		cout<<0<<endl;
	return 0;
}