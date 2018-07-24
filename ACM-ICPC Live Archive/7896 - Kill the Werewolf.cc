#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005     // Número máximo de nodos
#define MAXE 100005   // Número máximo de aristas
#define INF 20000000

int e,n,s,t; // n: Numero de nodos, s: Nodo source, t: Nodo sink
int dis[MAXN],head[MAXN],work[MAXN];
int cap[MAXE],flow[MAXE],point[MAXE],nxt[MAXE];

inline void init() { e = 0; memset(head, -1, sizeof head); }

// Inserta arista v->u con capacidad c1 y u->v con capacidad c2
inline void add(int v, int u, int c1, int c2 = 0)
{
	point[e]=u,cap[e]=c1,flow[e]=0,nxt[e]=head[v],head[v]=(e++); 
	point[e]=v,cap[e]=c2,flow[e]=0,nxt[e]=head[u],head[u]=(e++);
}

inline bool dinic_bfs() // Arma el grafo nivelado
{
	memset(dis, -1, sizeof dis); dis[s] = 0;
	queue<int> q; q.push(s);
	while(!q.empty()) 
	{
		int v = q.front(); q.pop();
		for(int i = head[v]; i >= 0; i = nxt[i])
			if(flow[i] < cap[i] && dis[point[i]] < 0) 
			{
				dis[point[i]] = dis[v] + 1;
				q.push(point[i]);
			}
	}
	return (dis[t] >= 0);
}

inline int dinic_dfs(int v, int limit) // Encuentra flujos bloqueantes
{
	if(v == t) return limit;
	for(int &i = work[v]; i >= 0; i = nxt[i]) 
	{
		int u = point[i], tmp;
		if(flow[i] < cap[i] && dis[u] == dis[v] + 1 && (tmp = dinic_dfs(u, min(limit, cap[i] - flow[i]))) > 0) 
		{
			flow[i] += tmp; 
			flow[i^1] -= tmp;
			return tmp;
		}
	}
	return 0;
}

inline int dinic_flow()
{
	int ans = 0;
	while(dinic_bfs()) // Mientras haya un grafo nivelado..
	{
		for(int i = 0; i < n; i++) work[i] = head[i];
			while(1)
			{
				int f = dinic_dfs(s, INF); // Encontrar flujo bloqueante
				if(f == 0) break;          // Si no hay mas flujo, terminar
				ans += f;                  // Agregar flujo
			}
	}
	return ans;
}

int neig[55][2],freq[55];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,num,ans,con;
	while(cin>>num)
	{
		memset(freq,0,sizeof freq);
		for(int i=1;i<=num;i++)
		{
			cin>>neig[i][0]>>neig[i][1];
			freq[neig[i][0]]++;
			freq[neig[i][1]]++;
		}
		ans=0;
		n=num*2+2;
		s=0;
		t=num*2+1;
		for(int i=1;i<=num;i++)
		{
			init();
			con=0;
			for(int k=1;k<=num;k++)
				if(i!=k && neig[k][0]!=i && neig[k][1]!=i)
				{
					add(s,k,1);
					add(k,num+neig[k][0],1);
					add(k,num+neig[k][1],1);
					con++;
				}
			
			for(int k=1;k<=num;k++)
				if(k!=neig[i][0] && k!=neig[i][1])
					add(num+k,t,freq[i]-1);
				else
					add(num+k,t,freq[i]-2);
			if(dinic_flow()<con)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}