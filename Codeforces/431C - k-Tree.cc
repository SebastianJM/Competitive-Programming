#include <bits/stdc++.h>
using namespace std;

long long n, k, d,dp[105],comp[105];
#define modu 1000000007
int main()
{
	cin >> n >> k >> d;
	memset(comp, 0, sizeof comp);
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= k; i++)
	{
		dp[i]= 1;
		if (i >= d)
			comp[i]++;
	}
	for (int i = 1; i < n; i++)
	{
		if (dp[i])
		{
			for (int z = 1; z <= k; z++)
				if (i + z <= n)
				{
					dp[i + z] += dp[i];
					if (z >= d)
						comp[i + z] += dp[i];
					else
						comp[i + z] += comp[i];
					dp[i + z] %= modu;
					comp[i + z] %= modu;
				}
		}
	}
	cout << comp[n] << endl;
	return 0;
}