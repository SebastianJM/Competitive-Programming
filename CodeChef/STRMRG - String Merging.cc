#include <bits/stdc++.h>
using namespace std;
const int MAX = 5005;
int dp[MAX][MAX];

int LCS(const string &s, int n, const string &t, int m) 
{

	for(int i = 0; i <= n; i++) 
		dp[i][0] = 0;
	for(int i = 0; i <= m; i++) 
		dp[0][i] = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	return dp[n][m]; 
}


int main() 
{
	int t,n,m;
	string a,b,new_a,new_b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>a>>b;
		new_a=new_b="";
		for(int i=0;i<n;)
		{
			char val=a[i];
			while(i<n && a[i]==val)
				i++;
			new_a.push_back(val);
		}
		for(int i=0;i<m;)
		{
			char val=b[i];
			while(i<m && b[i]==val)
				i++;
			new_b.push_back(val);
		}
		n=new_a.size();
		m=new_b.size();
		
		int ans=LCS(new_a,n,new_b,m);
		cout<<(n+m-ans)<<endl;
	}
	return 0;
}