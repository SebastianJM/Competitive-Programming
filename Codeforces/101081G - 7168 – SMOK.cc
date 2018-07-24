#include <bits/stdc++.h>
using namespace std;

#define MAX 105
const int MOD = 1e9 + 7;

struct Matrix
{
	unsigned long long M[MAX][MAX];
	bool trans[MAX][MAX];
	Matrix operator * (Matrix &a) 
	{
		Matrix ans;
		memset(ans.M, 0, sizeof ans.M);
		memset(ans.trans,0,sizeof ans.trans);
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
				for(int k = 0; k < MAX; k++)
				{
					ans.M[i][j] = (ans.M[i][j] + (M[i][k] * a.M[k][j]) % MOD) % MOD;
					ans.trans[i][j]=(ans.trans[i][j]|(trans[i][k] & a.trans[k][j]));
				}
					
		return ans;
	}
	
	Matrix pow(int p)
	{
		Matrix ans, b = *this;
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
			{
				ans.M[i][j] = (i == j);
				ans.trans[i][j]=(i==j);
			}
				
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,r,k,x,y;
	cin>>n>>r>>k;
	Matrix m;
	memset(m.M,0,sizeof m.M);
	memset(m.trans,false,sizeof m.trans);
	for(int i=0;i<r;i++)
	{
		cin>>x>>y;
		m.M[x-1][y-1]+=1LL;
		m.M[y-1][x-1]+=1LL;
		m.trans[x-1][y-1]=true;
		m.trans[y-1][x-1]=true;
	}
	
	
	m=m.pow(k);

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(j!=i+1)
				cout<<" ";
			if(m.M[i][j]==0 && !m.trans[i][j])
				cout<<-1;
			else
				cout<<m.M[i][j];
		}
			
		cout<<"\n";
	}
		
	return 0;
}