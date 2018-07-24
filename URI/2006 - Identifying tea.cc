#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d,e,f,r;
	while(cin>>f)
	{
		r=0;
		cin>>a>>b>>c>>d>>e;
		if(a==f)
			r++;
		if(b==f)
			r++;
		if(c==f)
			r++;
		if(d==f)
			r++;
		if(e==f)
			r++;
		cout<<r<<endl;
	}
	return 0;
}