#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int Funcion(int n,int suma)
{
	if(n==1)
		return suma;
	else
		return Funcion(n-1,suma+pow(n-1,2));
}
int main()
{
	int t;
	while(1)
	{
		cin>>t;
		if(t==0)
			break;
		cout<<Funcion(t,pow(t,2))<<endl;
	}
    return 0;
}