#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int sum[101];
int value[101];

int suma(int l,int r)
{
	return sum[r]-sum[l]+value[l];
}

int solve(int l,int r)
{
	if(l>r)
		return 0;
	if(l==r)
		return value[l];
	if(dp[l][r]!=INT_MIN)
		return dp[l][r];
	int ans=INT_MIN;
	for(int i=0;i<=r-l;i++)
		ans=max(ans,max( suma(l,l+i)-solve(l+i+1,r),suma(r-i,r)-solve(l,r-i-1)  ));
	return dp[l][r]=ans;
}

int main() 
{
	int n;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++)
		{
			cin>>value[i];
			sum[i]=value[i]+(i>0?sum[i-1]:0);
		}
		for(int i=0;i<101;i++)
			for(int e=0;e<101;e++)
				dp[i][e]=INT_MIN;
		cout<<solve(0,n-1)<<endl;
	}
	return 0;
}