#include <iostream>
using namespace std;

#define N 1000000007

int x,y;

int f(int n)
{
	if(n==1) return x;
	if(n==2) return y;
	return f(n-1)-f(n-2);	
}
int main()
{
	int s;
	cin>>x>>y>>s;
	s=f((s-1)%6+1);
	if(s<0)
	{
		s%=N;
		s=N+s;
	}
	cout<<s%N;
	return 0;
}
