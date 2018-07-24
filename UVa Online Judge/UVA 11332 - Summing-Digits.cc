#include <iostream>
using namespace std;
 
unsigned int Recursividad(unsigned int n,unsigned int sum)
{
	while(n!=0)
	{
		sum+=n%10;
		n/=10;
	}
	if(sum>=10)
		Recursividad(sum,0);
	else 
		return sum;
}
int main() {
	unsigned int t;
	while(1)
	{
		cin>>t;
		if(t==0)
			return 0;
		cout<<Recursividad(t,0)<<endl;
	}
 
	return 0;
}