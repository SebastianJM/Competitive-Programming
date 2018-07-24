#include <iostream>

using namespace std;

int main()
{
	int t,s,q,res(0);
	cin>>t>>s>>q;
	while(t>s)
	{
		res++;
		s*=q;
	}
	cout<<res;
	return 0;
}