#include <iostream>
using namespace std;

int main() 
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c==0)
		a==b?cout<<"YES":cout<<"NO";
	else if((b<a && c>0) ||(a<b && c<0))
		cout<<"NO";
	else
		if(!((b-a)%c))
			cout<<"YES";
		else
			cout<<"NO";
	return 0;
}