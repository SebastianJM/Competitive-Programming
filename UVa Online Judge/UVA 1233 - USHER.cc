#include <bits/stdc++.h>

using namespace std;

#define INF 20000000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii g;
vi dist;
vi preva;
int n;

void init()
{
	preva = vi(n, -1);
	dist = vi(n, INF);
}
void dijkstra(int s)
{
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dist[v] >= d)
			for (int i = 0; i < (int)g[v].size(); i++)
			{
				int u = g[v][i].second;
				int w = g[v][i].first;
				if (dist[v] + w < dist[u])
				{
					dist[u] = dist[v] + w;
					preva[u] = v;
					pq.push(ii(dist[u], u));
				}
			}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,b,a,c,r,p;
	vi pari;
	cin>>t;
	while(t--)
	{
		cin>>b>>n;
		n++;
		cin>>r;
		pari=vi(r);
		g=vvii(n);
		for(int i=0;i<r;i++)
			cin>>pari[i];

		
		for(int i=1;i<n;i++)
		{
			cin>>p;
			for(int j=0;j<p;j++)
			{
				cin>>a>>c;
				g[i].push_back(ii(a,c));
			}
		}
		
		
		int mini=INF;
		for(int i=0;i<r;i++)
		{
			init();
			dijkstra(pari[i]);
			mini=min(mini,dist[0]);
		}
		int ans=0,m=0;
		while(m<b)
		{
			m+=mini;
			if(m>=b)
				break;
			m--;
			ans++;
		}
		cout<<ans<<endl;;
	}
	cin>>t;
	return 0;
}