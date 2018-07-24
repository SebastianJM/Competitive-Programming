#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii; 
typedef vector<ii> vii;   
typedef vector<vii> vvii;   

#define INF 20000000

int n;
vvii g;

vi dijkstra(int s) 
{
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	vi dist;
	dist = vi(n, INF);
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
					pq.push(ii(dist[u], u)); 
				}
			}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int b,f,c,t,x,y,w;
	while(cin>>n>>b>>c>>f>>t)
	{
		if(n<0)
			return 0;
		g=vvii(n);
		for(int i=0;i<t;i++)
		{
			cin>>x>>y>>w;
			g[x-1].push_back(ii(w,y-1));
			g[y-1].push_back(ii(w,x-1));
		}
		vi dis_n=dijkstra(f-1),dis_b=dijkstra(b-1),dis_c=dijkstra(c-1);
		int ju=0;	
		for(int i=0;i<n;i++)
			if(dis_b[i]+dis_n[i]==dis_n[b-1] && dis_b[i]+dis_c[i]==dis_c[b-1])
				ju=max(ju,dis_b[i]);
		cout<<ju<<" "<<dis_c[b-1]-ju<<" "<<dis_n[b-1]-ju<<"\n";		
	}

	return 0;
}