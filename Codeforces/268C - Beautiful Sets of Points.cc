#include <iostream>

using namespace std;

int main()
{
	int n, m,a;
	cin >> n >> m;
	if (n == 0 && m == 0)
		cout << 0;
	else
	{
		if (m > n)
		{
			a = m;
			m = n;
			n = a;	
		}
		cout << m + 1 << endl;
		for (int i = 0; i < m + 1; i++)
		{
			cout << i << " " << m - i << endl;
		}
	}

	return 0;
}