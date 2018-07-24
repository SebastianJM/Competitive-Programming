#include <bits/stdc++.h>

using namespace std;

int dp[1<<15];
int v[15];
int n;

int rec(int bitmask,int pos)
{
	if(bitmask==(1<<n)-1)
		return 0;
	if(dp[bitmask]!=-1)
		return dp[bitmask];
	int ans=0;
		
	for(int i=pos;i<n-2;i++)
		if(!(bitmask&(1<<i)))
			for(int j=i+1;j<n-1;j++)
				if(!(bitmask&(1<<j)))
					for(int k=j+1;k<n;k++)
						if(!(bitmask&(1<<k)))
							ans=max(ans,((v[i]+v[j]+v[k]>=20)?1:0)+rec(bitmask|(1<<i)|(1<<j)|(1<<k),i));

	return dp[bitmask]=ans;
}

int main() 
{
	int t=1;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++)
			cin>>v[i];
		memset(dp,-1,sizeof dp);
		cout<<"Case "<<t++<<": "<<rec(0,0)<<endl;
	}
	return 0;
}