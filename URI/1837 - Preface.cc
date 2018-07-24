#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b;

	if(a>=0&&b<0||a>=0&&b>0||a%b==0)
		cout<<a/b<<" "<<a%b<<endl;
	else if(a<0 && b>0)
	{
		a=abs(a);
		c=a;
		a=b*(a/b+1);
		cout<<(-a/b)<<" "<<a-c<<endl;
	}
	else
	{
		c=a;
		a=(a/b+1)*b;
		cout<<a/b<<" "<<c-a<<endl;
	}

	return 0;
}
