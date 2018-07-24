#include <iostream>

using namespace std;

int main()
{
	double a,b;
	while(cin>>a>>b)
	{
		if(a==0.0 && b==0.0)
			cout<<"Origen"<<endl;
		else if(a==0.0 && b!=0.0)
			cout<<"Eje Y"<<endl;
		else if(a!=0.0 && b==0.0)
			cout<<"Eje X"<<endl;
		else if(a>0.0 && b<0.0)
			cout<<"Q4"<<endl;
		else if(a>0.0 && b>0.0)
			cout<<"Q1"<<endl;
		else if(a<0.0 && b>0.0)
			cout<<"Q2"<<endl;
		else
			cout<<"Q3"<<endl;
	}
	return 0;
}
