#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 10004
VVi g;
bool visit[MAX];

Pii bfs(int x)
{
	queue<Pii> q;
	q.push(Pii(x,0));
	int node=x,y;
	int dis=0;
	while(!q.empty())
	{
		
		x=q.front().first;
		y=q.front().second;
		q.pop();
		visit[x]=true;	
		if(dis<y)
		{
			dis=y;
			node=x;
		}
		for(int i=0;i<g[x].size();i++)
			if(!visit[g[x][i]])
			{
				visit[g[x][i]]=true;
				q.push(Pii(g[x][i],y+1));	
			}
	}	
	return Pii(node,dis);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,u,v;
	cin>>n;
	g=VVi(n+1);
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	memset(visit,false,sizeof visit);
	int fur=bfs(1).first; //Primer BFS para encontrar el nodo más lejano a 1
	memset(visit,false,sizeof visit);
	int ans=bfs(fur).second; //Segundo BFS para hallar el diámetro
	cout<<ans<<"\n";
}	