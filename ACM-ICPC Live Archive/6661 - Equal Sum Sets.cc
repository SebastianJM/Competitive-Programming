#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k,p;
	while (1)
	{
		cin >> n >> k >> p;
		if (n == 0 && k == 0 && p == 0)
			return 0;
		int total(0);
		for (int mask = 0; mask < (1 << n); mask++)
		{
			if (__builtin_popcount(mask) == k)
			{				
				vector<int> gg;

				for (int i = 0; i < n; i++)
				{
					if (mask & (1 << i))						
						gg.push_back(i + 1);
					

				}

				int t = 0;
				for (int j = 0; j < k; j++)
					t += (gg[j]);
				if (t == p)
					total++;
				
			}
		}

		cout << total << endl;
	}
	return 0;
}