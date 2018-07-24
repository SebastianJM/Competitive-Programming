#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> vec;
int n;
void update(int pos,int v)
{
	pos--;
	for (vec[pos += n] = v; pos >>= 1;)
		vec[pos] = vec[pos << 1] + vec[pos << 1 | 1];
}

void calcular(int l,int r)
{
	long long res = 0;
	l--;
	r--;
	for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if (l & 1) res += vec[l];
		if (!(r & 1)) res += vec[r];
	}
	printf("%d\n",res);
}
int main()
{
	string tipo;
	int q,l,r;
	int aux1,aux2;
	q = 1;
	
	while (scanf("%d",&n))
	{
		if (n == 0)
			return 0;
		vec=vector<int>(2*n);
		if(q>1)
			printf("\n");
		for (int i = n; i < n * 2; i++)
			scanf("%d",&vec[i]);
		for (int i = n - 1; i > 0; i--)
		{
			vec[i] = vec[i << 1] +vec[i << 1 | 1];
		}
		printf("Case %d:\n",q);
		while (cin>>tipo)
		{
			if (tipo == "END")
			{
				
				break;
			}
			scanf("%d %d",&l,&r);
			if (tipo == "S")
			{
				update(l, r);				
			}
			else
			{
				calcular(l, r);				
			}
		}
				
		q++;
	}
	return 0;
}