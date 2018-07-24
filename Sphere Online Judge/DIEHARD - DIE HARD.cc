// DYNAMIC PROGRAMMING - 24/04/2016

#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];
int vida[3] = { 3, -5, -20 };
int armor[3] = { 2, -10, 5 };

int solve(int h, int a, int from)
{
	if (h <= 0 || a <= 0)
		return 0;
	if (dp[h][a]>0) return dp[h][a];
	int ans = 0;
	for (int i = 0; i < 3; i++)
		if (from != i)
			ans = max(ans, solve(h + vida[i], a + armor[i], i) + 1);
	return dp[h][a] = ans;
}
int main()
{
	int t, h, a;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> h >> a;
		
		int res = 0;
		for (int i = 0; i < 3; i++)
		{
			memset(dp, 0, sizeof dp);
			res = max(res, solve(h, a, i));
		}
		cout << res-1 << endl;
	}
	
	return 0;
}