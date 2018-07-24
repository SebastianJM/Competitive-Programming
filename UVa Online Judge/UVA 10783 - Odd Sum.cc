#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int a,b,t,sum;
	cin>>t;
	int con=0;
	while(con!=t)
	{
		cin>>a>>b;
		sum=0;
		for(int i=a;i<=b;i++)
			if(i%2==1)
				sum+=i;
		cout<<"Case "<<con+1<<": "<<sum<<endl;
		con++;
	}
    return 0;
}