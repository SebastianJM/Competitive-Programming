#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair <int,long long> ii;
typedef vector<vector<ii>> vvi;
typedef vector<bool> vb;

#define MAX 100005

int n;
int T[MAX];
int P[MAX][17];
int L[MAX];
long long W[MAX];
vvi g;
void init()
{
	for(int i=0;i<n;i++)
		for(int j=0;1<<j<n;j++)
			P[i][j]=-1;
	for(int i=0;i<n;i++)
		P[i][0]=T[i];
	for(int j=1;1<<j<n;j++)
		for(int i=0;i<n;i++)
			if(P[i][j-1]!=-1)
				P[i][j]=P[P[i][j-1]][j-1];

}

int lca(int p,int q)
{	
	int lg;
	if(L[p]<L[q]) swap(p,q);
	for(lg=1; (1<<lg) <=L[p] ;lg++); lg--;
	for(int i=lg;i>=0;i--)
		if(L[p]-L[q]>=(1<<i))
			p=P[p][i];
	if(p==q)
		return p;
	for(int i=lg;i>=0;i--)
		if(P[p][i]!=-1&&P[p][i]!=P[q][i])
		{
			p=P[p][i];q=P[q][i];}
	return P[p][0];
}

vb disc;
void build(int s)
{
    int w,u;
	queue<int> q;q.push(s);
	disc=vb(n,false);disc[s]=true;
	T[s]=-1;L[s]=0;W[s]=0;
	while(!q.empty())
	{
		int v=q.front();q.pop();
		for(int i=0;i<(int)g[v].size();i++)
		{
			w=g[v][i].second;
			u=g[v][i].first;
			if(!disc[u])
			{
				q.push(u); disc[u]=true;
				T[u]=v;
				L[u]=L[v]+1;
				W[u]=W[v]+w;
			}
		}
	}
}
long long dist(int p,int q)
{
	return W[p]+W[q]-W[lca(p,q)]*2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int u,v,t;
    while(1)
    {
        cin>>n;
        if(n==0)
            return 0;
        g=vvi(n);
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[i].push_back(ii(u,v));
            g[u].push_back(ii(i,v));
        }
        build(0);
        init();
        
        cin>>t;
        for(int i=0;i<t;i++)
        {

            cin>>u>>v;
            cout<<dist(u,v);
            
            if(i!=t-1)
                cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}