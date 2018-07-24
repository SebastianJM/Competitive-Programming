#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
int n,m,dis[1004];
bool vis[1004],val[1004];

void bfs(int a)
{
	queue<pair<int,int> > q;
	q.push(make_pair(a,0));
	dis[a]=0;
	vis[a]=true;
	while(!q.empty())
	{
		int f=q.front().first;
		int s=q.front().second;
		dis[f]=s;
		q.pop();
		vis[f]=true;
		for(int i=0;i<g[f].size();i++)
		{
			if(!vis[g[f][i]])
			{
				vis[g[f][i]]=true;
				q.push(make_pair(g[f][i],s+1));
			}
		}
	}
}

bool dfs(int a)
{
	for(int i=0;i<g[a].size();i++)
	{
		if(dis[a]<dis[g[a][i]])
		{
			if(!dfs(g[a][i]))
				return true;
		}
	}
	return false;
}

int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int u,v;
	cin>>n>>m;
	g=vector<vector<int> >(n+1);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(val,0,sizeof val);
	memset(vis,0,sizeof vis);

	bfs(1);

	if(dfs(1))
		cout<<"Vladimir"<<endl;
	else
		cout<<"Nikolay"<<endl;
	return 0;
}