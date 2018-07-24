#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long> vec;

long long llgcd(long long x, long long y) 
{
	long long t;
	while (x%y)
	{
		t = x; 
		x = y; 
		y = t%y;
	}
	return y;
}
int main()
{
	int t,n;
	long long aux;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vec=vector<long long>(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		aux=vec[0];
		for(int i=0;i<n-1;i++)
			aux=llgcd(aux,vec[i+1]);
		
		cout<<aux<<endl;
	}
	
	return 0;
}

