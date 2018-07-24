#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define A 100005
#define BLOCK 316 // ~sqrt(N)
#define LSOne(S) (S & (-S)) // Least Significant One

typedef vector<int> vi;
typedef vector<vi> vvi;

int  color[N],cnt[N], ans[N], size[N],answer;

vi t,pos,val; 
vvi g;
int n,au;

void inc(int i, int val) 
{
	for(i++; i <= n; i += LSOne(i))
		t[i] += val;
}
int rsq(int i) 
{
	int sum = 0;
	for(i++; i; i -= LSOne(i))
		sum += t[i];
	return sum;
}
int rsq(int l, int r) 
{
	return rsq(r) - rsq(l - 1);
}

struct node 
{
	int L, R, i,k;
	node(){}
};

node q[N];

bool cmp(node x, node y) 
{
	if(x.L/BLOCK != y.L/BLOCK) 
		return x.L/BLOCK < y.L/BLOCK;
	return x.R < y.R;
}
	
void add(int position) 
{
	if(cnt[color[val[position]]]>=0)
		inc(cnt[color[val[position]]],-1);
	cnt[color[val[position]]]++;
	if(cnt[color[val[position]]]>=0)
		inc(cnt[color[val[position]]],1);
}

void remove(int position)
{
	if(cnt[color[val[position]]]>=0)
		inc(cnt[color[val[position]]],-1);
	cnt[color[val[position]]]--;
	if(cnt[color[val[position]]]>=0)
		inc(cnt[color[val[position]]],1);
}

int dfs(int u,int from)
{
	int tam=1;
	pos[u]=au++;
	val.push_back(u);
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]!=from)
			tam+=dfs(g[u][i],u);
	return size[u]=tam;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m,u,v;
	cin>>n>>m;
	g=vvi(n);
	pos=vi(n);
	t=vi(N+5,0);
	au=0;
	for(int i=0;i<n;i++)
		cin>>color[i];
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,0);
	
	for(int i=0; i<m; i++) 
	{
		cin>>u>>q[i].k;
		q[i].L=pos[u-1];
		q[i].R=pos[u-1]+size[u-1]-1;
		q[i].i = i;
	}
		
	sort(q, q + m, cmp);
	
	int currentL = q[0].L, currentR = q[0].L,L,R;
	
	for(int i=0; i<m; i++) 
	{
		L = q[i].L, R = q[i].R;
		while(currentL < L) 
			remove(currentL++);
		while(currentL > L) 
			add(--currentL);
		while(currentR <= R) 
			add(currentR++);
		while(currentR > R+1) 
			remove(--currentR);

		ans[q[i].i] = rsq(q[i].k,N);
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<"\n";
	
	return 0;
}
