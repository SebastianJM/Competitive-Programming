#include <bits/stdc++.h>

using namespace std;

int dp[102][102*500];
int mon[102],n;

int knap(int max_peso)
{
	for(int i=0;i<=max_peso;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int e=0;e<=max_peso;e++)
			if(mon[i-1]<=e)
				dp[i][e]=max(dp[i-1][e],dp[i-1][e-mon[i-1]]+mon[i-1]);
			else
				dp[i][e]=dp[i-1][e];
	return dp[n][max_peso];
}
int main() 
{
	int t,suma;
	cin>>t;
	while(t--)
	{
		cin>>n;
		suma=0;
		for(int i=0;i<n;i++)
		{
			cin>>mon[i];
			suma+=mon[i];
		}
		int res=knap(suma/2);
		cout<<suma-2*res<<endl;
		
	}
	return 0;
}