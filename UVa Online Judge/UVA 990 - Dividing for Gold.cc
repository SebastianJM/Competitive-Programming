#include <bits/stdc++.h>

using namespace std;

int t,w,n,a,b;
int tiempo[33];
int valor[33];
int dp[33][1003];
bool resu[31][1001][31];

int knap(int max_tiempo)
{
	for(int i=0;i<=n;i++)
		for(int e=0;e<=max_tiempo;e++)
			for(int z=0;z<n;z++)
				resu[i][e][z]=false;
	for(int i=0;i<=max_tiempo;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int e=0;e<=max_tiempo;e++)
			if(tiempo[i-1]<=e)
			{
				if(dp[i-1][e]>dp[i-1][e-tiempo[i-1]]+valor[i-1])
				{
					dp[i][e]=dp[i-1][e];
					for(int z=0;z<n;z++)
						resu[i][e][z]=resu[i-1][e][z];
					//resu[i][e][i-1]=true;
				}
				else
				{
					dp[i][e]=dp[i-1][e-tiempo[i-1]]+valor[i-1];
					for(int z=0;z<n;z++)
						resu[i][e][z]=resu[i-1][e-tiempo[i-1]][z];
					resu[i][e][i-1]=true;
				}
				
			}
			else
			{
				dp[i][e]=dp[i-1][e];
				for(int z=0;z<n;z++)
					resu[i][e][z]=resu[i-1][e][z];
				//resu[i][e][i-1]=true;
			}
	return dp[n][max_tiempo];
}
int main() 
{
	int fir=1;
	while(cin>>t>>w)
	{
		if(!fir)
			cout<<endl;
		fir=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			tiempo[i]=a*w+2*a*w;
			valor[i]=b;
		}
		cout<<knap(t)<<endl;
		int tot=0;
		for(int i=0;i<n;i++)
			if(resu[n][t][i])
				tot++;
		cout<<tot<<endl;
		for(int i=0;i<n;i++)
			if(resu[n][t][i])
				cout<<tiempo[i]/(3*w)<<" "<<valor[i]<<endl;
		
	}
	return 0;
}