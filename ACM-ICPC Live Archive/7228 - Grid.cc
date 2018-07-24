#include <bits/stdc++.h>

using namespace std;

#define MAXN 50*50+3     // Número máximo de nodos
#define MAXE 100005   // Número máximo de aristas
#define INF 20000000

int e,n,s,t; // n: Numero de nodos, s: Nodo source, t: Nodo sink
int dis[MAXN],head[MAXN],work[MAXN];
int cap[MAXE],flow[MAXE],point[MAXE],nxt[MAXE];

void init() 
{ 
	e = 0; memset(head, -1, sizeof head); 
}

// Inserta arista v->u con capacidad c1 y u->v con capacidad c2
void add(int v, int u, int c1, int c2 = 0)
{
	point[e]=u,cap[e]=c1,flow[e]=0,nxt[e]=head[v],head[v]=(e++); 
	point[e]=v,cap[e]=c2,flow[e]=0,nxt[e]=head[u],head[u]=(e++);
}
bool dinic_bfs() // Arma el grafo nivelado
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

int dinic_dfs(int v, int limit) // Encuentra flujos bloqueantes
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

int dinic_flow()
{
	int ans = 0;
	while(dinic_bfs()) // Mientras haya un grafo nivelado..
	{
		for(int i = 0; i < n; i++) work[i] = head[i];
		while(1)
		{
			int f = dinic_dfs(s, INF); // Encontrar flujo bloqueante
			if(f == 0) 
				break;          // Si no hay mas flujo, terminar
			ans += f;                  // Agregar flujo
		}
	}
	return ans;
}

int ind[52][52];
int m[52][52];
int disp[MAXN];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q,f,c;
	cin>>q;
	while(q--)
	{
		cin>>f>>c;
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
				cin>>m[i][e];
		int nodes=1,left;
		init();
		s=0;
		for(int i=0;i<f;i++)
			for(int e=(i%2?1:0);e<c;e+=2)
			{
				ind[i][e]=nodes++;
				disp[ind[i][e]]=m[i][e];
				add(s,ind[i][e],m[i][e],0);
			}
		left=nodes;
		t=f*c+1;
		for(int i=0;i<f;i++)
			for(int e=(i%2?0:1);e<c;e+=2)
			{
				ind[i][e]=nodes++;
				disp[ind[i][e]]=m[i][e];
				add(ind[i][e],t,m[i][e],0);
			}
		
		n=t+1;
		
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
				if(ind[i][e]<left)
					for(int k=0;k<4;k++)
						if(i+y[k]>=0 && i+y[k]<f && e+x[k]>=0 && e+x[k]<c)
							add(ind[i][e],ind[i+y[k]][e+x[k]],INF,0);

		int ans=dinic_flow(),xx=0;
		for(int i = head[xx]; i >= 0; i = nxt[i]) // Revisar cada arista
		  if(flow[i]>=0)
		    ans+=disp[point[i]]- flow[i];
		  
		for(xx=left;xx<t;xx++)
			for(int i = head[xx]; i >= 0; i = nxt[i]) // Revisar cada arista
			  if(point[i]==t)
			    ans+=disp[xx]- flow[i];
			  
		cout<<ans<<endl;
	}
	return 0;
}