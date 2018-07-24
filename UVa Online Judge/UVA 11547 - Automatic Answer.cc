#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		cout<<abs(((((n*567/9)+7492)*235/47-498)/10)%10)<<endl;	
	}
    return 0;
}