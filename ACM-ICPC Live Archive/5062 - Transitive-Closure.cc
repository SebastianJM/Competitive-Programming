#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<vector<bool> > adj;
int n;

void bfs(int a)
{
	int u,v;
	queue<int> q;
	vector<bool> visit(n,false);
	q.push(a);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		
		visit[u]=true;
		for(int i=0;i<g[u].size();i++)
		{
			v=g[u][i];
			if(!visit[v])
			{
				q.push(v);
				adj[a][v]=true;
			}
		}
	}
}
int main() 
{
	int t,r,u,v,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		g=vector<vector<int> >(n);
		adj=vector<vector<bool> >(n,vector<bool>(n,false));
		ans=0;
		for(int i=0;i<r;i++)
		{
			cin>>u>>v;
			g[u-1].push_back(v-1);
		}
		for(int i=0;i<n;i++)
			bfs(i);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(adj[i][j])
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}