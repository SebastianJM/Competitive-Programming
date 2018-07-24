#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
int val[100005];

void dfs(int n,int d)
{
	val[n]=d;
	for(int i=0;i<g[n].size();i++)
		if(val[g[n][i]]==0)
		{
			
			val[g[n][i]]=d*(-1);
			dfs(g[n][i],d*(-1));
		}
}
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,p,u,v,c;
	cin>>n>>p;
	g=vector<vector<int> >(n+10);
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		for(int j=0;j<c;j++)
		{
			cin>>u;
			g[i].push_back(u);
		}
	}
	memset(val,0,sizeof val);
	dfs(p,1);
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()<=1)
		{
			if(val[i]<0)
				cout<<"CCW"<<endl;
			else if(val[i]>0)
				cout<<"CW"<<endl;
			else
				cout<<"-"<<endl;
		}
	}
	return 0;
}