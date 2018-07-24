#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n,sum;
	cin >> t;
	while (t--)
	{
		cin >> n;
		sum = 0;
		vector<int> hombres = vector<int>(n);
		vector<int> mujeres = vector<int>(n);
		for (int i = 0; i < n; i++)
			cin >> hombres[i];
		for (int i = 0; i < n; i++)
			cin >> mujeres[i];
		sort(hombres.rbegin(), hombres.rend());
		sort(mujeres.rbegin(), mujeres.rend());
		for (int i = 0; i < n; i++)
			sum += hombres[i] * mujeres[i];
		cout << sum << endl;
	}
	
	return 0;
}

