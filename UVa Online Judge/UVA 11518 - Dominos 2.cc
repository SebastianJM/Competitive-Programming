#include <bits/stdc++.h>

using namespace std;

int n,m,l,res;
vector<vector<int>> g;
vector<bool> visitados;

void dfs(int x)
{
	if(!visitados[x])
	{
		res++;
		visitados[x]=true;
	
		for(int i=0;i<g[x].size();i++)
			if(!visitados[g[x][i]])
				dfs(g[x][i]);
			
	}
}
int main()
{
	int t,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l;
		g=vector<vector<int>>(n);
		
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			g[u-1].push_back(v-1);
		}
		visitados=vector<bool>(n,false);
		res=0;
		for(int i=0;i<l;i++)
		{
			cin>>u;
			dfs(u-1);
			
		}
		cout<<res<<endl;
	}
	return 0;
}
