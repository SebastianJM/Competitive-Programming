#include <iostream>
using namespace std;

int main() 
{
	unsigned long long n;
	cin>>n;
	if(n<=2)
		cout<<-1<<endl;
	else
	{
		if(n&1)
			cout<<(n*n-1)/2<<" "<<(n*n+1)/2<<endl;
		else
			cout<<(n/2)*(n/2)-1<<" "<<(n/2)*(n/2)+1<<endl;
	}
	return 0;
}