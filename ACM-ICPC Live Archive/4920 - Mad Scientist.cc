#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			return 0;
		vector<int> vec = vector<int>(n+1);
		for (int i = 1; i <= n; i++)
			cin >> vec[i];
		vec[0] = 0;
		bool fi = false;
		for (int i = 1; i <= n; i++)
			for (int e = 0; e < vec[i]-vec[i-1]; e++)
				if (!fi)
				{
					cout << i;
					fi = true;
				}
				else
					cout << " " << i;
		cout << endl;

	}
	return 0;
}