#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>c;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i>c)
				break;
			for(int e=1;e<=m;e++)
			{
				if(i*e>c)
					break;
				else if(i*e==c)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 