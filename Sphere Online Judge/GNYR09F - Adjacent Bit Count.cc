// DYNAMIC PROGRAMMING - 27/04/2016
/* Mismo patrón: 
l=longitud de la cadena
k=cantidad de pares
b=último bit de la cadena (0 o 1)
dp[l][k][0]=dp[l-1][k][0]+dp[l-1][k][1]
dp[l][k][1]=dp[l-1][k-1][1]+dp[l-1][k][0]
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[103][103][2];

int main()
{
	memset(dp,0,sizeof dp);
	dp[1][0][0]=dp[1][0][1]=1;
	for(int i=2;i<=100;i++)
	{
		dp[i][0][0]=dp[i-1][0][1]+dp[i-1][0][0];
		dp[i][0][1]=dp[i-1][0][0];
	}
	
	for(int i=2;i<=100;i++)
		for(int j=1;j<=100;j++)
		{
			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j][0];
		}
	int t,a,n,k;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>n>>k;
		cout<<i+1<<" "<<dp[n][k][0]+dp[n][k][1]<<endl;
	}
	return 0;
}
