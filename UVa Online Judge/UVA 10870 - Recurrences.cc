#include <bits/stdc++.h>

using namespace std;

long long MOD=1e9+5;
#define MAX 17
int LIM;
struct Matrix
{
	long long M[MAX][MAX];
	Matrix operator * (Matrix &a)
	{
		Matrix ans;
		memset(ans.M,0,sizeof ans.M);
	
		for(int i=0;i<LIM;i++)
			for(int j=0;j<LIM;j++)
				for(int k=0;k<LIM;k++)
					ans.M[i][j]=(ans.M[i][j]+(M[i][k]*a.M[k][j])%MOD)%MOD;
		return ans;
	}
	Matrix pow(int p)
	{
		Matrix ans,b=*this;
		for(int i=0;i<LIM;i++)
			for(int j=0;j<LIM;j++)
				ans.M[i][j]=(i==j);
		while(p)
		{
			if(p&1)
				ans=ans*b;
			p>>=1;
			b=b*b;
		}
		return ans;
	}
};
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long d,n,m;
	
	while(1)
	{
		cin>>d>>n>>m;
		if(!d)
			return 0;
		Matrix a,f;
		memset(a.M,0,sizeof a.M);
		memset(f.M,0,sizeof f.M);
		for(int i=0;i<d;i++)
			cin>>a.M[0][i];
		for(int i=d-1;i>=0;i--)
			cin>>f.M[i][0];
		if(n<=d)
			cout<<f.M[n-1][0]%m<<"\n";
		else
		{
			LIM=d+1;
			MOD=m;
			int it=0;
			for(int i=1;i<d;i++)
				a.M[i][it++]=1;
			Matrix aux=a;
			aux=aux.pow(n-d);
			aux=aux*f;
			cout<<aux.M[0][0]<<"\n";
		}
	}
	return 0;
}