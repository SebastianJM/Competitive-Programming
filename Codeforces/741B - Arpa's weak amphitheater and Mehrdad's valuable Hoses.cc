#include <bits/stdc++.h>

using namespace std;

int n,m,w,tot;
bool visit[1005];
int weight[1005],beauty[1005],dp[3003][1002];
vector<int> W,B,T;
vector<vector<int> > g;
vector<pair<int,int> > posT;
queue<int> q;

void bfs(int xx,int t)
{
	int sW=0,sB=0,x;
	while(!q.empty())
		q.pop();
	q.push(xx);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		sW+=weight[x];
		sB+=beauty[x];
		W.push_back(weight[x]);
		B.push_back(beauty[x]);
		T.push_back(t);
		visit[x]=true;
		for(int i=0;i<g[x].size();i++)
			if(!visit[g[x][i]])
			{
				visit[g[x][i]]=true;
				q.push(g[x][i]);
			}
	}
	W.push_back(sW);
	B.push_back(sB);
	T.push_back(t);
}
int knapsack()
{
	for(int i=0;i<=w;i++)
		for(int j=0;j<=B.size();j++)
			dp[j][i]=0;
	for(int i=1;i<tot;i++)
		for(int k=posT[i].first;k<=posT[i].second;k++)
			for(int j=posT[i-1].first;j<=posT[i-1].second;j++)
				for(int x=0;x<=w;x++)
					if(x-W[k]>=0)
						dp[k][x]=max(dp[k][x],max(dp[j][x],dp[j][x-W[k]]+B[k]));
					else
						dp[k][x]=max(dp[k][x],dp[j][x]);

	int ans=0;
	for(int i=posT[tot-1].first;i<=posT[tot-1].second;i++)
		ans=max(ans,dp[i][w]);
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,l,r;
	cin>>n>>m>>w;
	g=vector<vector<int> >(n+1);
	for(int i=1;i<=n;i++)
		cin>>weight[i];
	for(int i=1;i<=n;i++)
		cin>>beauty[i];
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	memset(visit,false,sizeof visit);
	W.push_back(0); B.push_back(0); T.push_back(0);
	posT.push_back(make_pair(0,0)); tot=1;
	for(int i=1;i<=n;i++)
		if(!visit[i])
		{
			l=W.size();
			bfs(i,tot);
			posT.push_back(make_pair(l,W.size()-1));
			tot++;
		}

	cout<<knapsack()<<endl;
	return 0;
}