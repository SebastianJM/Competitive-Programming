#include <iostream>
using namespace std;

int main() 
{
	int d,r,t,cr,ct,i=4;
	cin>>d>>r>>t;
	cr=ct=0;
	while(cr+ct!=r+t)
	{
		cr+=i;
		if(i-d>=3)
			ct+=i-d;
		i++;
	}
	cout<<r-cr<<endl;
	return 0;
}