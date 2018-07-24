#include <bits/stdc++.h>
using namespace std;

int dp[750];
vector<int> global;

int desc(int n)
{
	int ans=0;
	while(n>0)
	{
		ans+=pow(n%10,2);
		n/=10;
	}
	return ans;
}
bool rep(int n)
{
	for(int i=0;i<global.size();i++)
		if(n==global[i])
			return true;
	return false;
}
int rec(int n)
{
	int s=desc(n);
	if(dp[s]!=-1)
		return dp[s];
	
	if(s==1 || rep(s))
		return dp[s]=s;
	global.push_back(s);
	return dp[s]=rec(s);
}
int main() 
{
	memset(dp,-1,sizeof dp);
	int t,a=1;
	cin>>t;
	while(t>=a)
	{
		global=vector<int>(1);
		cin>>global[0];
		
		int ans=rec(global[0]);
		if(ans==1)
			cout<<"Case #"<<a++<<": "<<global[0]<<" is a Happy number."<<endl;
		else
			cout<<"Case #"<<a++<<": "<<global[0]<<" is an Unhappy number."<<endl;
	}
	return 0;
}