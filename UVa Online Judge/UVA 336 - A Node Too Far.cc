#include <bits/stdc++.h>

using namespace std;

int res;
vector<vector<int>> g;
vector<pair<bool,int> > visitados;

inline void dfs(int x,int dis)
{
	if(dis>=1)
	{
		visitados[x].second=dis;
		if(!visitados[x].first)
		{
			res++;
			visitados[x].first=true; 
		}
		for(int i=0;i<g[x].size();i++)	
			if(g[x][i]!=x && dis-1>visitados[g[x][i]].second)
				dfs(g[x][i],dis-1);
	}	
	else if(dis==0)
		if(!visitados[x].first)
		{
			res++;
			visitados[x].first=true; 
		}
}
int main()
{
	int t,u,v,c=1;
	while(1)
	{
		cin>>t;
		if(!t)
			return 0;
		map<int,int> cod;
		int e=0;
		g=vector<vector<int>>();
		for(int i=0;i<t;i++)
		{
			cin>>u>>v;		
			if(cod.find(u)==cod.end())
			{
				g.push_back(vector<int>());
				cod[u]=e++;
			}
			if(cod.find(v)==cod.end())
			{
				g.push_back(vector<int>());
				cod[v]=e++;
			}
			g[cod[u]].push_back(cod[v]);
			g[cod[v]].push_back(cod[u]);
		}
		while(1)
		{
			cin>>u>>v;
			if(!u && !v)
				break;
			res=0;
			visitados=vector<pair<bool,int> >(e,pair<bool,int>(false,-1));
			dfs(cod[u],v);
			//cout<<res<<" "<<e<<endl;
			cout<<"Case "<<c++<<": "<<e-res<<" nodes not reachable from node "<<u<<" with TTL = "<<v<<"."<<endl;
		}
		
	}
	return 0;
}