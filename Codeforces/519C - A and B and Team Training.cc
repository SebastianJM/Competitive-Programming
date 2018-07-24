#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long x,n;
    cin>>x>>n;
	if(x==0||n==0)  
	{
		cout<<0;
		return 0;
	}
	if(x<n)
	{
		if(n<2*x)
			cout<<(x+n)/3;
		else
			cout<<x;
	}
	else if(x>n)
	{
		if(x<2*n)
			cout<<(x+n)/3;
		else
			cout<<n;
	}
	else
		cout<<(x+n)/3;
    return 0;
}