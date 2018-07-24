#include <bits/stdc++.h>

using namespace std;

#define MAX 200004

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long con[MAX],x,n,a,ans;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ans+=con[a^x];
		con[a]++;
	}
	cout<<ans<<endl;
	
	return 0;
}