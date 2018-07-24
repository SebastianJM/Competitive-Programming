#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define INF 2000000000

int main()
{
	int t, n,m;
	cin >> t;
	while (t--)
	{
		cin >> n>>m;
		vi vec(m);
		vi cant(10002,INF);
		for (int i = 0; i < m; i++)
			cin >> vec[i];
		cant[0] = 0;
		for (int i = 0; i < m; i++)
			for (int e = 10000; e >= 0; e--)
				if (cant[e] < INF && e+vec[i]<=10000)
					cant[e + vec[i]] = min(cant[e+vec[i]],cant[e] + 1);
		int i;
		for (i = n; i <= 10000; i++)
			if (cant[i] < INF)
				break;
		cout << i << " " << cant[i] << endl;
	}
	return 0;
}