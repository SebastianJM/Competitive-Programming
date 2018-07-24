#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 100005
#define VAL 1000005

struct query
{
    int id,a,b,l,r,opc;
    query(){}
    query(int pid,int pa,int pb,int pl,int pr,int popc):id(pid),a(pa),b(pb),l(pl),r(pr),opc(popc){}
};

vector<vector<query> > solve;
query du;
VVi g;
int n;          // n: Número de nodos
int T[MAX];     // T[i]    : Padre del nodo i.     
int P[MAX][17]; // P[i][j] : Padre del nodo i a distancia 2^j.
int L[MAX];     // L[i]    : Cantidad de nodos entre i y la raíz.
int W[MAX];
int t[VAL * 2];      // Segment Tree (raíz -> 1)
int ans[MAX];
ll tamano_criba;
bitset<VAL> bs;
bool primo[VAL];
bool vis[MAX];
// ------- ERATHOSTENES CRIBE --------
void criba(int limite)
{
    memset(primo,false,sizeof primo);
    tamano_criba = limite + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i <= tamano_criba; i++)
        if(bs[i])
        {
            for(ll j = i * i; j <= tamano_criba; j += i)
                bs[j] = 0;
            primo[i]=true;
        }
}
// ------- LCA AND TREE CONSTRUCTION --------
void init()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; 1 << j < n; j++)
      P[i][j] = -1;
  for(int i = 0; i < n; i++) 
    P[i][0] = T[i];
  for(int j = 1; 1 << j < n; j++)
    for(int i = 0; i < n; i++)
      if(P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}
int lca(int p, int q) // p: Nodo, q: Nodo
{
    int lg;
    if(L[p] < L[q]) swap(p, q);
    for(lg = 1; 1 << lg <= L[p]; lg++); 
    lg--;
    for(int i = lg; i >= 0; i--)
        if(L[p] - L[q] >= (1 << i))
            p = P[p][i];
    if(p == q)
        return p;
    for(int i = lg; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
        p = P[p][i], q = P[q][i];
    return P[p][0];
}
Vb disc;

void build(int s) // s: Nodo raíz (Elegido al azar)
{
  queue<int> q; q.push(s); 
  disc = Vb(n, false); 
  disc[s] = true;
  T[s] = -1; L[s] = 0;
  while(!q.empty())
  {
    int v = q.front(); q.pop();
    for(int i = 0; i < (int)g[v].size(); i++) 
    {
      int u = g[v][i];
      if(!disc[u])
      {
        q.push(u); disc[u] = true;
        T[u] = v;        // El padre del nodo u es el nodo v
        L[u] = L[v] + 1; // Número de nodos para llegar al nodo u
      }
    }
  }
}
// ------- SEGMENT TREE --------

void update(int i, int val) // i debe estar en [0, N-1]
{
   for(t[i += VAL] += val; i >>= 1; )
      t[i] = t[i << 1] + t[i << 1 | 1];
}
int query_rsq(int l, int r) // Query en el rango [l,r]
{
   int ans = 0;
   for(l+=VAL, r+=VAL; l <= r; l = (l+1) >> 1, r = (r-1) >> 1)
   {
      if(  l & 1 ) ans = ans + t[l];
      if(!(r & 1)) ans = ans + t[r];
   }
   return ans;
}

void dfs_solve(int x)
{
  bool is_pr = primo[W[x]];
  vis[x]=true;

  if(is_pr)
    update(W[x],1);
  
  for(int i=0;i<solve[x].size();i++)
  {
      du=solve[x][i];
      if(du.opc>0)
        ans[du.id]+=query_rsq(du.l,du.r);

      else
        ans[du.id]-=2*query_rsq(du.l,du.r);

  }
  for(int i=0;i<g[x].size();i++)
  {
    if(!vis[g[x][i]])
    {
      vis[g[x][i]]=true;
      dfs_solve(g[x][i]);
    }
  }
  if(is_pr)
    update(W[x],-1);
 
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q,u,v,l,r;
    criba(1000003);
    cin>>n>>q;
    g=VVi(n+1);
    solve=vector<vector<query> >(n+1);
    
    for(int i=0;i<n;i++)
        cin>>W[i];
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    build(0);
    init();
    memset(t,0,sizeof t);
    memset(vis,0,sizeof vis);
    int anc;
    for(int i=0;i<q;i++)
    {
        cin>>u>>v>>l>>r;
        u--;v--;
        solve[u].pb(query(i,u,v,l,r,1));
        solve[v].pb(query(i,u,v,l,r,1));
        anc=lca(u,v);
        if(primo[W[anc]] && W[anc]>=l && W[anc]<=r)
          ans[i]++;
        solve[anc].pb(query(i,u,v,l,r,-1));
    }
    dfs_solve(0);
    for(int i=0;i<q;i++)
      cout<<ans[i]<<"\n";
    return 0;
}
