#include <bits/stdc++.h>
using namespace std;

int dp[1<<20],v[20];
int n,suma;

int solve(int len,int bitmask)
{
	if(dp[bitmask]!=-1)
		return dp[bitmask];
	if(len>suma/4)
		return 0;
	if(len==suma/4)
	{
		if(bitmask==(1<<n)-1)
			return 1;
		len=0;
	}
	for(int i=0;i<n;i++)
		if((bitmask & (1<<i)) == 0 && solve(len+v[i],bitmask|(1<<i)))
			return 1;
	return dp[bitmask]=0;
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof dp);
		cin>>n;
		suma=0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			suma+=v[i];
		}

		if(suma%4==0 && solve(0,0))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	
	return 0;
}