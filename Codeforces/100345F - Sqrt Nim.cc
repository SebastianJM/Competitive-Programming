#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(ll n)
{
	ll c=2,a=3,p;

	while(c<=n)
	{
		p=1;
		bool is=false;
		for(int i=1;i<=37;i++)
		{
			p<<=1;
			if(a==p)
			{
				is=true;
				break;
			}
			else if(p>a)
				break;
		}
		if(is)
		{
			if(n==c)
				return false;
			c+=a;
			a++;
		}
		else
		{
			if(n==c)
				return false;
			c+=a;
			if(n==c)
				return false;
			c+=a;
			a++;
		}
	}
	return true;
}

int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	ll n;
	cin>>n;
	if(n==1|| ok(n))
		cout<<"WIN"<<endl;
	else 
		cout<<"LOSE"<<endl;
	
}