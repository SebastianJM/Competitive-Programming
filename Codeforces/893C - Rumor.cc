#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF 1000000020
vvi g;
vi cost;
vi group;
vi ans;
int n,z;
void dfs(int x)
{
	group[x]=z;
	for(int i=0;i<g[x].size();i++)
		if(group[g[x][i]]<0)
		{
			group[g[x][i]]=z;
			dfs(g[x][i]);
		}
		
}
void trav()
{
	z=0;
	for(int i=0;i<n;i++)
		if(group[i]<0)
		{
			dfs(i);
			z++;
		}
	
}
int main() 
{
	int r,a,b;
	cin>>n>>r;
	cost=vi(n);
	g=vvi(n);
	group=vi(n,-1);
	ans=vi(n,INF);
	for(int i=0;i<n;i++)
		cin>>cost[i];
	for(int i=0;i<r;i++)
	{
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	trav();
	for(int i=0;i<n;i++)
		ans[group[i]]=min(ans[group[i]],cost[i]);
	long long sol=0;
	for(int i=0;i<z;i++)
		sol+=ans[i];
	
	
	cout<<sol<<endl;
	return 0;
}