#include<iostream>

using namespace std;
 
int main()
{
	int n,a,aux,res(0);
	cin>>n;
	a=0;
	while(n--)
	{
		cin>>aux;
		a+=aux;
		if(a<0)
		{
			res++;
			a=0;
		}
	}
	cout<<res;

	return 0;
}