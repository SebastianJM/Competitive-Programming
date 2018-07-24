#include <iostream>
using namespace std;

int main() 
{
	int a,b,c;
	while(1)
	{
		cin>>a>>b>>c;
		if(!a && !b && !c)
			break;
		if(b-a==c-b)
			cout<<"AP "<<c+(c-b)<<endl;
		else
			cout<<"GP "<<c*(c/b)<<endl;
	}
	return 0;
}