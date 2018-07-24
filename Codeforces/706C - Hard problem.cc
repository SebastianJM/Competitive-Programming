#include <bits/stdc++.h>

using namespace std;
int main() 
{
	int n;
	vector<vector<long long> > dp;
	vector<long long> cost;
	vector<string> st;
	vector<string> r_st;
	
	cin>>n;
	dp=vector<vector<long long> >(n,vector<long long>(2,-1));
	cost=vector<long long>(n);
	st=vector<string>(n);
	r_st=vector<string>(n);
	for(int i=0;i<n;i++)
		cin>>cost[i];
	for(int i=0;i<n;i++)
	{
		cin>>st[i];
		r_st[i]=st[i];
		reverse(r_st[i].begin(),r_st[i].end());
	}
	dp[0][0]=0;
	dp[0][1]=cost[0];
	for(int i=1;i<n;i++)
	{
		
		if(dp[i-1][0]!=-1 && st[i]>=st[i-1])
		{
			if(dp[i-1][1]!=-1 && st[i]>=r_st[i-1])
				dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
			else
				dp[i][0]=dp[i-1][0];
		}
		else if(dp[i-1][1]!=-1 && st[i]>=r_st[i-1])
			dp[i][0]=dp[i-1][1];
		if(dp[i-1][0]!=-1 && r_st[i]>=st[i-1])
		{
			if(dp[i-1][1]!=-1 && r_st[i]>=r_st[i-1])
				dp[i][1]=min(dp[i-1][0]+cost[i],dp[i-1][1]+cost[i]);
			else
				dp[i][1]=dp[i-1][0]+cost[i];
		}
		else if(dp[i-1][1]!=-1 && r_st[i]>=r_st[i-1])
			dp[i][1]=dp[i-1][1]+cost[i];
	}
	long long ans=LLONG_MAX;
	if(dp[n-1][0]!=-1)
		ans=dp[n-1][0];
	if(dp[n-1][1]!=-1)
		ans=min(ans,dp[n-1][1]);
	if(ans<LLONG_MAX)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}