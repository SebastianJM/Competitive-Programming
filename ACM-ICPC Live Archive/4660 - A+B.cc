#include <bits/stdc++.h>

using namespace std;

int max_base(int n)
{
	int ans=0;
	while(n>0)
	{
		ans=max(ans,n%10);
		n/=10;
	}
	return ans+1;
}

int to10(int base,int n)
{
	int ans=0,it=0;
	while(n>0)
	{
		ans+=(n%10)*pow(base,it++);
		n/=10;
	}
	return ans;
}
int main() 
{
	int t,a,b,max_a,max_b,aa,bb;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		max_a=max_base(a);
		max_b=max_base(b);
		aa=a;
		bb=b;
		for(int i=max_a;i<=10;i++)
			aa=min(aa,to10(i,a));
		for(int i=max_b;i<=10;i++)
			bb=min(bb,to10(i,b));
		
			
		cout<<aa+bb<<endl;
	}
	return 0;
}