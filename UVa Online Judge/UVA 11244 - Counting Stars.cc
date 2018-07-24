#include <iostream>
#include <cstring>

#include <bits/stdc++.h>
using namespace std;

char matriz[106][106];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c, f;
	while (1)
	{
		cin >> f >> c;
		if (!f && !c)
			return 0;
		memset(matriz, 0, sizeof matriz);
		int res = 0;
		for (int i = 1; i <= f; i++)
			for (int e = 1; e <= c; e++)
				cin >> matriz[i][e];
		for (int i = 1; i <= f; i++)
			for (int e = 1; e <= c; e++)
				if (matriz[i][e] == '*')
				{
					if (matriz[i - 1][e] != '*' && matriz[i - 1][e - 1] != '*' && matriz[i - 1][e + 1] != '*' && matriz[i][e - 1] != '*' && matriz[i][e + 1] != '*' && matriz[i + 1][e] != '*' && matriz[i + 1][e - 1] != '*' && matriz[i + 1][e + 1] != '*')
						res++;
					else
						e++;
				}
		cout << res << endl;
	}

	return 0;
}

