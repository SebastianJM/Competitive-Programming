#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 105
typedef long long ll;

ll max1DRangeSum(vector<ll> vec,int n)
{
	ll suma = 0;
	ll ans = vec[0];
	for (int i = 0; i < n; i++)
	{
		suma += vec[i];
		ans = max(ans, suma);
		if (suma < 0)
			suma = 0;
	}
	return ans;
}

ll max2DRangeSum(vector<vector<ll> > vec, int R, int C)
{
	if (!R || !C)
		return 0;

	vector<ll> vKadane(MAX);
	ll maxSum;

	ll ans = vec[0][0];
	for (int i = 0; i < R; i++)
	{
		for (int k = 0; k < C; k++)
			vKadane[k] = 0;
		for (int k = i; k < R; k++)
		{
			for (int m = 0; m < C; m++)
				vKadane[m] += vec[k][m];
			maxSum = max1DRangeSum(vKadane, C);
			ans = max(ans, maxSum);
		}
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<ll> > vec(n);
		for (int i = 0; i < n; i++)
			vec[i] = vector<ll>(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> vec[i][j];
		cout << max2DRangeSum(vec, n, n) << endl;
	}
	return 0;
}