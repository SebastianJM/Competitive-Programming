

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a,b,t,aux;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==0&&b==0)
			cout<<"0"<<endl;
		else
		{
			aux=1;
			for(int i=0;i<b;i++)
				aux*=10;
			for(int i=0;i<a;i++)
				aux*=26;
			cout<<aux<<endl;
		}
	}
	return 0;
}