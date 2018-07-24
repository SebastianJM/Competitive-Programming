#include <bits/stdc++.h>
using namespace std;

int main() 
{
	unsigned long long x,n;
	cin>>x>>n;
	if((x/n)&1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}