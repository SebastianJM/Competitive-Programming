#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,a,b,c,x,y,z,u;
	a=b=c=0;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>z;
		a+=x;
		b+=y;
		c+=z;
		u=min(a,min(b,c));
		if(u<30)
			cout<<"NO"<<endl;
		else
		{
			cout<<u<<endl;
			a-=u;
			b-=u;
			c-=u;
		}
	}
	return 0;
}
