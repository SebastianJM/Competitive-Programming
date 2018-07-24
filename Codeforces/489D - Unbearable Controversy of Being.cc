#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,m,u,v;
	cin>>n>>m;
	vector<vector<int> > g(n);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		g[u-1].push_back(v-1);
	}
	vector<int> rep;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		rep=vector<int>(n,0);
		for(int e=0;e<g[i].size();e++)
		{
			u=g[i][e];
			for(int j=0;j<g[u].size();j++)
				if(g[u][j]!=i) rep[g[u][j]]++;
		}
		for(int e=0;e<n;e++)
			if(rep[e]>1) ans+=rep[e]*(rep[e]-1)/2;
	}
	cout<<ans;
	return 0;
}