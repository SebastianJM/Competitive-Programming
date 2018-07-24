#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pllll;
typedef pair<int,Pii> PiPii;
typedef vector<PiPii> VPiPii;
typedef vector<VPiPii> VVPiPii;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 150004
#define INF INT_MAX
#define EPS 1e-7
#define MOD 1000000007

VVi g,su;
bool visit[MAX];
ll ans,conn;

void conn_comp(int x)
{
    visit[x]=true;
    ans++;
    conn+=su[x].size();
    for(int i=0;i<g[x].size();i++)
        if(!visit[g[x][i]])
        {      
            visit[g[x][i]]=true;
            conn_comp(g[x][i]);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    memset(visit,false,sizeof visit);
    cin>>n>>m;
    g=su=VVi(n+1);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        su[a].pb(b);
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i=1;i<=n;i++)
        if(!visit[i])
        {
            ans=0LL;
            conn=0LL;
            conn_comp(i);
            if(ans>1LL && conn!=ans*(ans-1LL)/2LL)
            {
                cout<<"NO\n";
                return 0;
            }
        }
    cout<<"YES\n";
    return 0;       
}


