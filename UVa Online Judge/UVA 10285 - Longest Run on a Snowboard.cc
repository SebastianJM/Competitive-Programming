#include <bits/stdc++.h>
using namespace std;

int dp[103][103];
int mat[103][103];
int f,c,t;
int top_down(int x,int y)
{
	if(dp[y][x]!=1)
		return dp[y][x];
	if(y>0 && mat[y][x]>mat[y-1][x]) dp[y][x]=max(dp[y][x],top_down(x,y-1)+1);
	if(x>0 && mat[y][x]>mat[y][x-1]) dp[y][x]=max(dp[y][x],top_down(x-1,y)+1);
	if(y<f-1 && mat[y][x]>mat[y+1][x]) dp[y][x]=max(dp[y][x],top_down(x,y+1)+1);
	if(x<c-1 && mat[y][x]>mat[y][x+1]) dp[y][x]=max(dp[y][x],top_down(x+1,y)+1);
	return dp[y][x];
}

int main() 
{
	string s;
	
	cin>>t;
	while(t--)
	{
		cin>>s>>f>>c;
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
			{
				cin>>mat[i][e];
				dp[i][e]=1;
			}
		//memset(dp,0,sizeof dp);
		int maxi=-1;
		
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
				maxi=max(top_down(e,i),maxi);
				
		
		cout<<s<<": "<<maxi<<endl;
	}
	return 0;
}