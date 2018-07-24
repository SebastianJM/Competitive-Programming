#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int ans=1,t=1;
		while(t%n!=0)
		{
			t=(t*10+1)%n;
			ans++;
		}
		cout<<ans<<endl;
	}
}