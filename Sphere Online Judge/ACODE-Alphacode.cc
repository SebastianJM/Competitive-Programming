// DYNAMIC PROGRAMMING 27/04/2016

#include <bits/stdc++.h>

using namespace std;

string s;
int dp[5005];

int count(int desde,int hasta)
{
	if(desde>=s.length()||hasta>=s.length())
		return 0;
	if(desde==hasta && s[desde]=='0' )
		return 0;
	if(hasta>desde && ( ((s[desde]-'0')*10+(s[hasta]-'0'))>26 ||s[desde]=='0'||hasta-desde>1))
		return 0;
	if(dp[hasta])
		return dp[hasta];
	if(hasta==s.length()-1)
		return 1;
	int ans=0;
	ans+=count(hasta+1,hasta+1)+count(hasta+1,hasta+2);
	return dp[hasta]=ans;
}
int main()
{
	while(1)
	{
		cin>>s;
		if(s[0]=='0')
			return 0;
		memset(dp,0,sizeof dp);
		cout<<count(0,0)+count(0,1)<<endl;
	}
	return 0;
}