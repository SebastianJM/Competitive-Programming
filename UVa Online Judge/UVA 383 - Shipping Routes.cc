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
	int t,k,r,q,peso;
	string s,a;
	//freopen ("out.txt","w",stdout);
	cin>>t;
	k=t;
	cout<<"SHIPPING ROUTES OUTPUT"<<endl;
	
	while(t--)
	{
		cout<<endl;
		map<string,int> mapa;
		int e=0;
		cin>>n>>r>>q;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			mapa[s]=e++;
		}
		g=vvii(n);
		for(int i=0;i<r;i++)
		{
			cin>>s>>a;
			g[mapa[s]].push_back(ii(1,mapa[a]));
			g[mapa[a]].push_back(ii(1,mapa[s]));
		}
		cout<<"DATA SET  "<<k-t<<endl;
		cout<<endl;
		for(int i=0;i<q;i++)
		{
			cin>>peso>>s>>a;
			init();
			dijkstra(mapa[s]);
			if(dist[mapa[a]]==INF)
				cout<<"NO SHIPMENT POSSIBLE"<<endl;
			else
				cout<<"$"<<dist[mapa[a]]*100*peso<<endl;
		}
	}
	cout<<endl;
	cout<<"END OF OUTPUT"<<endl;
    return 0;
}