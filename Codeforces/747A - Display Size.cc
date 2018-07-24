#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,mini=(1<<30),a,b;
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0 && (n/i)-i<mini)
		{
			mini=(n/i)-i;
			b=(n/i);
			a=i;
		}
	cout<<a<<" "<<b<<endl;
	return 0;
}