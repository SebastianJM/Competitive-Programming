#include <bits/stdc++.h>

using namespace std;

unsigned long long dp[302][302];
unsigned long long suma[302][302];
int main()
{
	char cad[100];
	int a, b, c;
	memset(dp,0,sizeof dp);
	memset(suma,0,sizeof suma);
	dp[0][0] = 1;
	for (int i = 1; i <= 300; i++)
		for (int e = i; e <= 300; e++)
			for (int k = 1; k <= 300; k++)
					dp[e][k] += dp[e-i][k - 1];
	suma[0][0]=1;
	for (int i = 1; i <= 300; i++)
		for (int e = 1; e <= i; e++)
			suma[i][e] += dp[i][e]+suma[i][e-1];
	
	while (gets(cad))
	{
		int tam = sscanf(cad, "%d %d %d", &a, &b, &c);
		if (tam == 1)
			cout << suma[a][a] << endl;
		else if (tam == 2)
			cout << suma[a][min(a,b)] << endl;		
		else if(b<=a)
			cout << suma[a][min(a,c)] - suma[a][b] +dp[a][b] << endl;
		else
			cout<<0<<endl;	
	}
	
	return 0;
}