#include <iostream>
using namespace std;
 
int main() {
	int n,suma(0);
	int x1,y1,x2,y2;
	cin>>n;
	while(n--)
	{
		cin>>x1>>y1>>x2>>y2;
		suma+=(x2-x1+1)*(y2-y1+1);
	}
	cout<<suma;
	return 0;
}