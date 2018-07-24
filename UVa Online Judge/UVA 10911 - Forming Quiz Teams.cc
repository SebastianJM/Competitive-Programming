#include <bits/stdc++.h>
using namespace std;

double dist[20][20];
double dp[1<<16+1];
int n;
vector<pair<int,int> > vp;

double distance(int x1,int y1,int x2,int y2)
{
	return hypot(abs(x1-x2),abs(y1-y2));
}

double solve(int a)
{
	if(dp[a]>-0.5)
		return dp[a];
	if(__builtin_popcount(a)>=n*2)
		return dp[a]=0.0;
	double ans=20000000000.0;
	int p1,p2;
	for(p1=0;p1<n*2;p1++)
		if(!((1<<p1) & a))
			break;
	for(p2=p1+1;p2<n*2;p2++)
		if(!((1<<p2) & a))
			ans=min(ans,dist[p1][p2]+solve(a|(1<<p1)|(1<<p2)));
	return dp[a]=ans;
}
int main() 
{
	string s;
	int x,y,t=1;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		vp=vector<pair<int,int> >(2*n,pair<int,int>(0,0));
		for(int i=0;i<=(1<<16);i++)
			dp[i]=-0.5;
		for(int i=0;i<2*n;i++)
		{
			cin>>s>>x>>y;
			vp[i].first=x;
			vp[i].second=y;
		}
		for(int i=0;i<2*n;i++)
			for(int j=0;j<=i;j++)
			{
				if(i!=j)
				{
					dist[i][j]=distance(vp[i].first,vp[i].second,vp[j].first,vp[j].second);
					dist[j][i]=dist[i][j];
				}
				else
					dist[i][j]=0;
			}
		printf("Case %d: %.2lf\n",t++,solve(0));
	}
	return 0;
}