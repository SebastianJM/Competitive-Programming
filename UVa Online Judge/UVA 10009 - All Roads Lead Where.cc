#include <bits/stdc++.h>


using namespace std;

#define INF 20000000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
vector<string> st;
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
	int r,q,t,pri=0;
	string a,b;
	cin>>t;
	while(t--)
	{
		cin>>r>>q;
		int e=0;
		map<string,int> city;
		g=vvii();
		st=vector<string>();
		for(int i=0;i<r;i++)
		{
			cin>>a>>b;
			if(city.find(a)==city.end())
			{
				g.push_back(vii());
				st.push_back(a);
				city[a]=e++;
			}
			if(city.find(b)==city.end())
			{
				g.push_back(vii());
				st.push_back(b);
				city[b]=e++;
			}
			g[city[a]].push_back(ii(1,city[b]));
			g[city[b]].push_back(ii(1,city[a]));
		}
		

		if(pri)
			cout<<endl;
		pri=1;
		for(int i=0;i<q;i++)
		{
			cin>>a>>b;
			n=e;
			init();
			dijkstra(city[a]);

			vector<string> res;
			int ori=city[a],des=city[b];
			while(ori!=des)
			{
				res.push_back(st[des]);
				des=preva[des];
			}
			res.push_back(a);
			for(int i=res.size()-1;i>=0;i--)
				cout<<res[i][0];
			cout<<endl;					
		}
	}
	return 0;
}	