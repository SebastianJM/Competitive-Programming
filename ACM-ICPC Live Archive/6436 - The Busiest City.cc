#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = 200000000;
const int MAX = 26;

vvi g;
vi dist;
int n;
ll ans;
int dfs(int x,int fr)
{
    dist[x]=1;
    if(g[x].size()==1)
        return 1;
    int c=0,d;
    ll ap=0LL;
    for(int i=0;i<g[x].size();i++)
        if(g[x][i]!=fr)
        {
            d=dfs(g[x][i],x);
            c+=d;
            ap+=d*(n-c-1);
            dist[x]+=d;
        }
    ans=max(ans,ap);
    return dist[x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,a,b,c,z=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        g=vvi(n);
        dist=vi(n);
        ans=0LL;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        for(int i=0;i<n;i++)
            if(g[i].size()>1)
            {
                dfs(i,i);
                break;
            }
      
        cout<<"Case #"<<z++<<": "<<ans<<"\n";
    }
    return 0;
}
