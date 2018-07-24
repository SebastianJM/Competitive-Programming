#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int n;
	cin>>n;


	for(int i=0,c=0;i<n;i++,c++)
	{
		if(c==4)
			c=0;
		if(c<2)
			cout<<"a";
		else if(c<4)
			cout<<"b";
		else
			cout<<"c";
	}
	cout<<"\n";
	return 0;
}