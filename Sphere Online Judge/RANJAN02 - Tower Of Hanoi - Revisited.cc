#include <stdio.h>
#include <iostream>

using namespace std;

long long tower(long long suma,int n)
{
	if(n==0)
		return suma;
	else
	{
		suma=3*suma+2;
		return tower(suma,n-1);
	}
	return 0;
}

int main()
{
	int t;
	int num;
	cin>>t;
	while(t--)
	{
		cin>>num;
		cout<<tower(0,num)<<endl;
	}
	getchar();
	return 0;
}