#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define N 1000005
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
 
int main()
{
	fastIO;
	int n, m, c;
	vector<int> a;
	cin >> n;
	a = vector<int>(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cin >> m;
	set<int> setc;
	for (int i = 0; i < m; i++)
	{
		cin >> c;
		setc.insert(c);
	}
	set<int> ans;
	bool valid;
	for (int j = 1; j <= 100; j++)
	{
		valid = true;
		for (int i = 0; i < n; i++)
		{
			if (setc.find(a[i] + j) == setc.end())
			{
				valid = false;
				break;
			}
		}
		if (valid)
			ans.insert(j);
	}
	bool first = true;
	for (auto i : ans)
	{
		if (!first)
			cout << " ";
		first = false;
		cout << i;
	}
		
	return 0;
}