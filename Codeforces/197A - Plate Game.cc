#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int a,b,r;
	cin>>a>>b>>r;
	
	if(2*r>a || 2*r>b)
		cout<<"Second"<<endl;
	else
		cout<<"First"<<endl;
	return 0;
}
