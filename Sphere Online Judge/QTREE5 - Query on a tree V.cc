#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
const int LOGN = 20;
const int INF = 1e9;
set<int> g[N];
multiset<int> ans[N];
multiset<int>::iterator it;
int par[N],sub[N],level[N];
bool state[N];
int DP[LOGN][N];
int n,m;

/*Using centroid Decomposition of a tree */

/*----------- Pre-Processing ------------*/
void dfs0(int u)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=DP[0][u])
		{
			DP[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it);
		}
}
void preprocess()
{
	level[0]=0;
	DP[0][0]=0;
	dfs0(0);
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if(d&(1<<i))
			b=DP[i][b];
	if(a==b)
		return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a=DP[i][a],b=DP[i][b];
	return DP[0][a];
}
int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}
/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)
		p=centroid;
	par[centroid]=p;
	for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid);
	}
	g[centroid].clear();
}
/*----------------- Handle the Queries -----------------*/

void update(int u)
{
	int x = u;
	if(!state[u])
	{
		while(1)
		{
			ans[x].insert(dist(x,u));
			if(x==par[x])
				break;
			x = par[x];
		}
	}
	else
	{
		while(1)
		{
			it=ans[x].find(dist(x,u));
			ans[x].erase(it);
			if(x==par[x])
				break;
			x = par[x];
		}
	}
	state[u]^=1;
}
int query(int u)
{
	int x = u;
	int ret=INF;
	while(1)
	{
		if(ans[x].size()!=0)
		{
			it=ans[x].begin();
			ret = min(ret,dist(u,x) + *it);
		}
		if(x==par[x])
			break;
		x = par[x];
	}
	return ret==INF?-1:ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int u,v;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		g[u-1].insert(v-1);
		g[v-1].insert(u-1);
	}
	preprocess();
	decompose(0,-1);
	
	memset(state,0,sizeof state);
	cin>>m;
	while(m--)
	{
		int t,v;
		cin>>t>>v;
		v--;
		if(t==0)
			update(v);
		else
			cout<<query(v)<<"\n";
	}
	return 0;
}