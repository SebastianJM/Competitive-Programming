#include <bits/stdc++.h>
using namespace std;

#define MAX 4
const int MOD = 1e9 + 7;
struct Matrix
{
	unsigned long long M[MAX][MAX];
	Matrix operator * (Matrix &a) 
	{
		Matrix ans;
		memset(ans.M, 0, sizeof ans.M);
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
				for(int k = 0; k < MAX; k++)
					ans.M[i][j] = (ans.M[i][j] + (M[i][k] * a.M[k][j]) % MOD) % MOD;
		return ans;
	}
	Matrix pow(int p)
	{
		Matrix ans, b = *this;
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
			ans.M[i][j] = (i == j);
		while(p)
		{
			if(p & 1)
			ans = ans * b;
			p >>= 1;
			b = b * b;
		}
		return ans;
	}
};

int main() {
	int n;
	cin>>n;
	Matrix m;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			m.M[i][j]=!(i==j);
	m=m.pow(n);
	cout<<m.M[3][3];
	return 0;
}