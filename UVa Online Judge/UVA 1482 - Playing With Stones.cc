#include <bits/stdc++.h>

using namespace std;

unsigned long long grunpy(unsigned long long a)
{
	if(a%2==0)
		return a/2;
	else
		return grunpy(a/2);
}

int main() 
{
	unsigned long long a,t,n,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			ans^=grunpy(a);
		}
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}