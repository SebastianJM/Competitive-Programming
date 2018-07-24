#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	for(int i=sqrt(n);i>1;i--)
		if(n%i==0)
			return false;
	return true;
}
int solve(int n)
{
	if(isPrime(n))
		return 1;
	if(n%2==0 || isPrime(n-2))
		return 2;
	
	return 3;
}
int main() 
{
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}