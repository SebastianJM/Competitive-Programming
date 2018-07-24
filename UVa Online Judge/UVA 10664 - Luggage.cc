#include <bits/stdc++.h>

using namespace std;

int t,n;
int num[22];
int dp[22][202];

int knap(int max_peso)
{
	for(int i=0;i<=max_peso;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int e=0;e<=max_peso;e++)
			if(num[i-1]<=e)
				dp[i][e]=max(dp[i-1][e],dp[i-1][e-num[i-1]]+num[i-1]);
			else
				dp[i][e]=dp[i-1][e];
	return dp[n][max_peso];
}
int main()
{		
	string s;
	cin>>t;
	getchar();
	while(t--)
	{
		n=0;
		getline(cin,s);
		stringstream op(s);
		int a,suma=0;
		while(op>>a)
		{
			num[n++]=a;
			suma+=a;
		}
		int res=suma-2*knap(suma/2);
		cout<<(res>0?"NO":"YES")<<endl;
	}
	return 0;
}