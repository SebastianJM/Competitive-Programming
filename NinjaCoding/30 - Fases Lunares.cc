#include <iostream>

using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(b<=2)
			cout<<"nueva"<<endl;
		else if(b>=3&&b<=96&&b>a)
			cout<<"creciente"<<endl;
		else if(b>=97&&b<=100)
			cout<<"llena"<<endl;
		else if(b>=3&&b<=96&&a>b)
			cout<<"menguante"<<endl;
	}
	return 0;
}