#include <bits/stdc++.h>
using namespace std;
 
int dp[5000];
 
int solve(int n)
{
	if(dp[n])
		return dp[n];
	int ans=__builtin_popcount(n);
	for(int i=11;i>0;i--)
		if((n & (1<<i)) &&(n & (1<<(i-1))))
		{
			if(i<11 && !(n & (1<<(i+1))))
				ans=min(ans,solve((((n|(1<<(i+1))) & (~(1 << i))) & (~(1 << i-1)))));
			if(i>1 && !(n & (1<<(i-2))))
				ans=min(ans,solve((((n|(1<<(i-2))) & (~(1 << i))) & (~(1 << i-1)))));
		}
	return dp[n]=ans;
}
int main() 
{
	int t,num;
	char c;
	cin>>t;
	memset(dp,0,sizeof dp);
	while(t--)
	{
		num=0;
		for(int i=11;i>=0;i--)
		{
			cin>>c;
			if(c=='o')
				num|=(1<<i);
		}
		cout<<solve(num)<<endl;
	}
	return 0;
}