#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c1,c_1,n,q,a;
	c1=c_1=0;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		a>0?c1++:c_1++;
	}	

	for(int i=0;i<q;i++)
	{
		cin>>a>>n;
		if((n-a+1)%2==0 && c1>=(n-a+1)/2 && c_1>=(n-a+1)/2)
			cout<<1<<endl;
		else
			cout<<0<<endl;			
	}
	return 0;
}