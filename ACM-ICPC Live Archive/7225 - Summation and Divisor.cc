#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a,ull b)
{
	return b==0? a : gcd(b,a%b);
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ull t,n,a,cero,ac,b,gcd_ans,c;
	cin>>t;
	c=1;
	while(t--)
	{
		cin>>n;
		ac=0;
		gcd_ans=0;
		for(ull i=0;i<n;i++)
		{
			cin>>a;
			cin>>cero;
			ac+=cero;
			for(ull e=1;e<a;e++)
			{
				cin>>b;
				gcd_ans=gcd(gcd_ans,labs(cero-b));
			}
		}
		gcd_ans=gcd(gcd_ans,ac);
		cout<<"Case #"<<c++<<": "<<gcd_ans<<endl;
	}
	return 0;
}