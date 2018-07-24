#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,t,l,carta,pa,pb;
	while(cin>>n>>t>>l)
	{
		n--;
		pa=pb=0;
		for(int i=0;i<n;i++)
		{
			cin>>carta;
			if(abs(t-carta)<=l)
			{
				i%2==0?pa+=abs(t-carta):pb+=abs(t-carta);
				t=carta;
			}
		}
		cout<<pa<<" "<<pb<<endl;
	}
	return 0;
}