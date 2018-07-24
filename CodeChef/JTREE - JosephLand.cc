// Example program
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<int> > vvi;
typedef vector<vector<pair<int,ll> > > vvii;

const int MAX = 1e5+5; 
const ll INF = 100000000000000000LL;
ll t[MAX*2]; 
ll dp[MAX];
int n; 

void build() 
{
    for(int i=0;i<=n;i++)
    {
        dp[i]=INF;
        t[i+n]=INF;
    }
    for(int i = n - 1; i > 0; i--) 
        t[i] = min(t[i << 1] , t[i << 1 | 1]);
}
void update(int i, ll val) 
{
    for(t[i += n] = val; i >>= 1; ) 
        t[i] = min(t[i << 1],t[i << 1 | 1]); 
}
ll query(int l, int r) 
{
    ll ans = INF;
    for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if( l & 1 ) ans = min(ans,t[l]); 
        if(!(r & 1)) ans = min(t[r],ans); 
    }
    return ans;
}

vvi g;
vvii ticket;

void dfs(int u,int h)
{
    for(int i=0;i<ticket[u].size();i++)
        dp[u]=min(dp[u],1LL*query(max(0,h-ticket[u][i].first),h-1)+ticket[u][i].second);
    update(h,dp[u]);
    for(int i=0;i<g[u].size();i++)
        dfs(g[u][i],h+1);
    update(h,INF);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int ti,v,k,u,q;
    ll c;
    cin>>n>>ti;
    n++;
    g=vvi(n);
    for(int i=0;i<n-2;i++)
    {
        cin>>u>>v;
        g[v].push_back(u);
    }
    ticket=vvii(n);
    for(int i=0;i<ti;i++)
    {
        cin>>v>>k>>c;
        ticket[v].push_back(make_pair(k,c));
    }
    build();
    dp[1]=0;
    update(0,0);
    dfs(1,0);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>u;
        cout<<dp[u]<<endl;
    }
    return 0;
}
