#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int t,a,b,c,d;
	int quad,rect,squa;
	cin>>t;
	while(t--)
	{
		quad=rect=squa=1;
		cin>>a>>b>>c>>d;
		if(a==b && a==c && a==d)
			cout<<"square"<<endl;
		else if((a==b && c==d) || (a==c && b==d) || (a==d && b==c))
			cout<<"rectangle"<<endl;
		else if(a<b+c+d && b<a+c+d && c<a+b+d && d<a+b+c)
			cout<<"quadrangle"<<endl;
		else
			cout<<"banana"<<endl;
	}
    return 0;
}