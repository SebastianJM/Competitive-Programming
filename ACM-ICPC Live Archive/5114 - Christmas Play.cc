#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t,n,k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (k == 1)
		{
			vector<int> vec = vector<int>(n);
			for (int i = 0; i < n; i++)
				cin >> vec[i];
			cout << 0 << endl;
		}
		else
		{
			vector<int> vec = vector<int>(n);
			for (int i = 0; i < n; i++)
				cin >> vec[i];
			sort(vec.rbegin(), vec.rend());
			if (n == k)
				cout << vec[0] - vec[n - 1] << endl;
			else
			{
				int mini = 1000000003;
				for (int i = 0; i <= n - k; i++)
				{
					if (vec[i] - vec[i + k-1] < mini)
						mini = vec[i] - vec[i + k-1];
				}
				cout << mini << endl;
			}
		}
	}
}
