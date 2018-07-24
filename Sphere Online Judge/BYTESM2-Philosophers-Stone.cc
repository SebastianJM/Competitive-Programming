#include <bits/stdc++.h>

using namespace std;

int main()
{
	int dp[103][103],t,f,c,a,maxi,res;
	cin >> t;
	for (int ii = 0;ii < t;ii++)
	{
		cin >> f >> c;
		res = 0;
		for (int i = 0;i < f;i++)
			for (int j = 0;j < c;j++)
			{
				cin >> dp[i][j];
				maxi = 0;
				if (i > 0)
				{
					maxi = max(maxi, dp[i - 1][j]);
					if (j > 0)
						maxi = max(maxi, dp[i - 1][j - 1]);
					if (j < c - 1)
						maxi = max(maxi, dp[i - 1][j + 1]);
				}
				dp[i][j] += maxi;
				if (i == f - 1)
					res = max(res, dp[i][j]);
			}
		cout << res << "\n";
	}
	return 0;
}