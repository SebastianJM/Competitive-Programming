#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, c, t = 1 , aux,r;
	while (true)
	{
		cin >> n >> c;
		if (n == 0 && c == 0)
			return 0;
		vector<int> vec = vector<int>(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		sort(vec.begin(), vec.end());
		cout << "CASE# " << t << ":" << endl;
		for (int i = 0; i < c; i++)
		{
			cin >> aux;
			r = 0;
			for (int e = 0; e < n; e++)
				if (vec[e] == aux)
				{
					cout << aux << " found at " << e + 1 << endl;
					r = 1;
					break;
				}
			if (r == 0)
				cout << aux << " not found" << endl;
		}
		t++;
	}
	return 0;

}