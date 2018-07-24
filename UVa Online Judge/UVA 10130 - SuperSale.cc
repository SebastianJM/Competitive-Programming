#include <bits/stdc++.h>

using namespace std;

int t,o,p,a,b;
int valor[1002];
int peso[1002];
int dp[1002][40];

int knap(int max_peso)
{
	for(int i=0;i<=max_peso;i++)
		dp[0][i]=0;
	for(int i=1;i<=o;i++)
		for(int e=0;e<=max_peso;e++)
			if(peso[i-1]<=e)
				dp[i][e]=max(dp[i-1][e],dp[i-1][e-peso[i-1]]+valor[i-1]);
			else
				dp[i][e]=dp[i-1][e];
	return dp[o][max_peso];
}
int main()
{	
	
	cin>>t;
	while(t--)
	{
		cin>>o;
		for(int i=0;i<o;i++)
			cin>>valor[i]>>peso[i];
		int suma=0;
		cin>>p;
		for(int i=0;i<p;i++)
		{
			cin>>a;
			suma+=knap(a);
		}
		cout<<suma<<endl;
	}
	return 0;
}