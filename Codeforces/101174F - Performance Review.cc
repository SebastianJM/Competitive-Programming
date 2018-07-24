#include <bits/stdc++.h>

using namespace std;

const int MAX = 1<<19; // Max number of elements
int tech[MAX],tim[MAX];
long long t[MAX*2],ans[MAX],temp[MAX]; // Segment Tree (Root is t[1])
int n; // Number of elements of the array
vector<vector<int> > g;

void build() // Builds the segment tree
{
	for(int i = n - 1; i > 0; i--) // For each non-leaf node..
		t[i] = t[i << 1] + t[i << 1 | 1]; // Update according to both children
}

void update(int i, long long val) // Sets array[i] to val (i in range [0, N-1])
{
	for(t[i += n] = val; i >>= 1; ) // Update leaf node, then go up..
		t[i] = t[i << 1] + t[i << 1 | 1]; // Update according to children
}

long long query(int l, int r) // Range Sum Query in range [l,r]
{
	long long answ = 0;
	for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if( l & 1 ) answ = answ + t[l]; // For left pointer, odd nodes matter
		if(!(r & 1)) answ = t[r] + answ; // For right pointer, even nodes matter
	}
	return answ;
}

void exec(int v)
{
	temp[v]=query(0,tech[v]-2);
	for(int i=0;i<g[v].size();i++)
		exec(g[v][i]);
	ans[v]=query(0,tech[v]-2)-temp[v];
	update(tech[v]-1,t[tech[v]-1+n]+tim[v]);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cant,u,man;
	n=0;
	cin>>cant;
	g=vector<vector<int> >(cant+1);
	memset(ans,0,sizeof ans);
	for(int i=1;i<=cant;i++)
	{
		cin>>u;
		if(u!=-1)
			g[u].push_back(i);
		else
			man=i;
		cin>>tech[i]>>tim[i];
		n=max(n,tech[i]);
	}
	
	build();
	exec(man);
	for(int i=1;i<=cant;i++)
		cout<<ans[i]<<endl;
	return 0;
}