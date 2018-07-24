#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

vector<vector<pair<int,int> > > g;
bool visit[MAX];
int parent[MAX];
int cost[MAX];
int actual[MAX];

void dfs(int x)
{
	visit[x]=true;
	for(int i=0;i<g[x].size();i++)
		if(!visit[g[x][i].first])
		{
			visit[g[x][i].first]=true;
			actual[g[x][i].first]=g[x][i].second;
			parent[g[x][i].first]=x;
			cost[g[x][i].first]=cost[x]+g[x][i].second;
			dfs(g[x][i].first);
		}
}
void climb(int x)
{
	while(x>1 && !visit[x])
	{
		visit[x]=true;
		x=parent[x];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q,a,b,c;
	while(cin>>n>>q)
	{
		g=vector<vector<pair<int,int> > >(n+1);
		memset(visit,0,sizeof visit);
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b>>c;
			
			g[a].push_back(make_pair(b,c));
			g[b].push_back(make_pair(a,c));
			ans+=c;
		}
		
		dfs(1);
		cost[1]=0;
		actual[1]=0;
		parent[1]=0;
		int dis=0;
		memset(visit,0,sizeof visit);
		for(int i=0;i<q;i++)
		{
			cin>>c;
			dis=max(dis,cost[c]);
			climb(c);
		}
		ans-=dis;
		for(int i=2;i<=n;i++)
			if(!visit[i])
				ans-=actual[i];
		cout<<ans<<endl;

	}
	return 0;
}