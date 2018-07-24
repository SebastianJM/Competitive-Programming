
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,k,a,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			ans+=floor(a/k);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

