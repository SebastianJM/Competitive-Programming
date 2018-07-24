#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	unsigned long long int n,p;
	cin>>n>>p;
	if(n%2==1)
		n++;
	if(p<=n/2)
		cout<<2*p-1<<endl;
	else
		cout<<2*(p-n/2)<<endl;
	return 0;
}