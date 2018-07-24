#include <iostream>
#include <vector>

using namespace std;
vector<long long> vec;
int n;
void update(int pos,int v)
{
	pos--;
	int aux1, aux2;
	for (vec[pos += n] = v; pos >>= 1;)
	{
		if (vec[pos << 1] > 0)
			aux1 = 1;
		else if (vec[pos << 1] < 0)
			aux1 = -1;
		else
			aux1 = 0;

		if (vec[pos << 1 | 1] > 0)
			aux2 = 1;
		else if (vec[pos << 1 | 1] < 0)
			aux2 = -1;
		else
			aux2 = 0;

		vec[pos] = aux1*aux2;
	}
}

void calcular(int l,int r)
{
	long long res = 1;
	l--;
	r--;
	for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if (l & 1) res *= vec[l];
		if (!(r & 1)) res *= vec[r];
	}
	if (res > 0)
		cout << "+";
	else if (res < 0)
		cout << "-";
	else
		cout << "0";
}
int main()
{
	char tipo;
	int q,l,r;
	int aux1, aux2;
	while (cin >> n >> q)
	{
		vec = vector<long long>(n*2);
		for (int i = n; i < n * 2; i++)
			cin >> vec[i];
		for (int i = n - 1; i > 0; i--)
		{
			if (vec[i << 1] > 0)
				aux1 = 1;
			else if (vec[i << 1] < 0)
				aux1 = -1;
			else
				aux1 = 0;

			if (vec[i << 1|1] > 0)
				aux2 = 1;
			else if (vec[i << 1|1] < 0)
				aux2 = -1;
			else
				aux2 = 0;

			vec[i] = aux1*aux2;
		}
		while (q--)
		{
			cin >> tipo >> l >> r;
			if (tipo == 'C')
				update(l, r);
			else
				calcular(l, r);
		}
		cout << endl;
	}
	return 0;
}