// MERGE SORT - INVERSION COUNT 24/04/2016

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<int> &v)
{
	int n = (int)v.size();
	if (n < 2) return 0;
	int n1 = n / 2, n2 = n - n / 2;
	vector<int> l(v.begin(), v.begin() + n1);
	vector<int> r(v.begin() + n1, v.end());
	ll ans = solve(l) + solve(r);
	int i1 = 0, i2 = 0;
	while (i1 < n1&&i2 < n2)
	{
		if (l[i1] <= r[i2])
		{
			v[i1 + i2] = l[i1];
			++i1;
		}
		else
		{
			ans += n1 - i1; v[i1 + i2] = r[i2];
			++i2;
		}
	}
	while (i1 < n1){ v[i1 + i2] = l[i1]; ++i1; }
	while (i2 < n2){ v[i1 + i2] = r[i2]; ++i2; }
	return ans;
}
int main()
{
	int t,n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << solve(v) << endl;
	}
	
	return 0;
}