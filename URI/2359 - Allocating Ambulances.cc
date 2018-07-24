#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;

#define INF (1<<30)

vvii g;
vi dist;
void dijkstra(int x)
{
	pair<int,int> p;
	queue<pair<int,int> > q;
	q.push(make_pair(x,0));
	dist[x]=0;
	int w;
	while(!q.empty())
	{
		x=q.front().first;
		w=q.front().second;
		q.pop();
		for(int i=0;i<g[x].size();i++)
		{
			p=g[x][i];
			if(p.second + w < dist[p.first])
			{
				dist[p.first]=p.second+w;
				q.push(make_pair(p.first,dist[p.first]));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,r,c,a,b,w;
	while(cin>>n>>r>>c)
	{
		g=vvii(n+1);
		dist=vi(n+1,INF);
		for(int i=0;i<r;i++)
		{
			cin>>a>>b>>w;
			g[a].push_back(make_pair(b,w));
			g[b].push_back(make_pair(a,w));
		}
		for(int i=0;i<c;i++)
		{
			cin>>a;
			dijkstra(a);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,dist[i]);
		cout<<ans<<endl;
	}
	return 0;
}