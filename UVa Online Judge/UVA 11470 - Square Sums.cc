#include <bits/stdc++.h>
using namespace std;

int matriz[12][12];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,a=1;
	while (1)
	{
		cin >> n;
		if (!n)
			return 0;
		int mitad = n % 2 == 1 ? n / 2 + 1 : n / 2;
		for (int i = 0; i < n; i++)
			for (int e = 0; e < n; e++)
				cin >> matriz[i][e];
		cout << "Case " << a << ":";
		int it=0;
		for (int i = 0; i < mitad; i++)
		{
			int suma = 0;
			for (int k = i; k < n - i; k++)			
				suma += matriz[i][k] + (i!=n-i-1?matriz[n - i - 1][k]:0);
			
			for (int k = i+1; k < n - i-1; k++)
				suma += matriz[k][i] + matriz[k][n - i - 1];
			cout << " " << suma  ;
		}
		cout << endl;
		a++;

	}
	return 0;

}

