#include <bits/stdc++.h>
using namespace std;
 
int f,c,ans;
int dp[100003],sumas[100003];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while(1)
	{
		cin>>f>>c;
		if(!f && !c)
			break;
		int maxi;
		for(int i=0;i<f;i++)
		{
			maxi=-1;
			for(int e=0;e<min(3,c);e++)
			{
				cin>>dp[e];
				if(e==2)
					dp[e]+=dp[e-2];
				maxi=max(maxi,dp[e]);
			}
			for(int e=3;e<c;e++)
			{
				cin>>dp[e];
				dp[e]+=max(dp[e-2],dp[e-3]);
			}
			if(c>3)
				maxi=max(dp[c-1],dp[c-2]);
			sumas[i]=maxi;
		}
		if(f!=3)
		{
			ans=sumas[0];
			for(int i=1;i<f;i++)
			{
				if(i>2)
					sumas[i]+=max(sumas[i-2],sumas[i-3]);
				else
					sumas[i]+=sumas[i-2];
			}
			ans=max(sumas[f-1],sumas[f-2]);
		}
		else
			ans=max(sumas[0]+sumas[2],sumas[1]);
		cout<<ans<<"\n";	

	}
	return 0;
}
