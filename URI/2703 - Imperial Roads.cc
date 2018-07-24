#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<pair<ll,int> > > gra;
typedef pair<int, int> ii; 
typedef pair<int, ii> iii; 

#define INF 20000000
#define MAXN 100004
#define MAXLOGN 20

vi pset;
inline void initSet(int n) { pset = vi(n); for(int i = 0; i < n; i++) pset[i] = i; }
inline int findSet(int i) { return (pset[i] == i)? i : (pset[i]= findSet(pset[i]));}
inline void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
inline bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

priority_queue<iii> edges; 
vector<map<int,ll> > mp;
gra g;
inline ll mst(int n) 
{
    g=gra(n);
    int mstSize = 0; 
    ll mstCost = 0; 
    initSet(n);
    while(!edges.empty() && mstSize < n - 1)
    {
        iii edge = edges.top(); 
        edges.pop();
        int x = edge.second.first, y = edge.second.second; 
        int w = labs(edge.first);
        if(!isSameSet(x,y)) 
        {
            unionSet(x,y);
            mstSize++; 
            mstCost += w; 
            g[x].push_back(make_pair(w,y));
            g[y].push_back(make_pair(w,x));
        }
    }
    return mstCost; 
}

int N, T[MAXN], P[MAXN][MAXLOGN], L[MAXN];
ll W[MAXN];
int maxi[MAXN][MAXLOGN];
inline void initialize()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; 1 << j<N; j++)
            maxi[i][j] = -INF;
}
inline void initialize_LCA()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; 1 << j<N; j++)
            P[i][j] = -1;
    for(int i = 0; i < N; i++) 
        P[i][0] = T[i];
    for(int j = 1; 1 << j < N; j++)
        for(int i = 0; i < N; i++)
            if(P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                maxi[i][j] = max(maxi[P[i][j - 1]][j - 1], maxi[i][j - 1]);
            }
}
inline int getMaxEdge(int p, int q) 
{
    int rmaxi = -INF, lg;
    if(L[p] < L[q]) 
        p ^= q ^= p ^= q;
    for(lg = 1; 1 <<lg <= L[p]; lg++); lg--;
        for(int i = lg; i >= 0; i--)
            if(L[p] - (1 << i) >= L[q])
            {
                rmaxi = max(rmaxi, maxi[p][i]); p = P[p][i];
            }
    if(p == q) 
        return rmaxi;
    for(int i = lg; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
        {
            rmaxi = max(rmaxi, maxi[p][i]);
            rmaxi = max(rmaxi, maxi[q][i]);
            p = P[p][i]; 
            q = P[q][i];
        }
    rmaxi = max(rmaxi, maxi[p][0]);
    rmaxi = max(rmaxi, maxi[q][0]);
    return rmaxi;
}
vector<int> discovered;
inline void build_LCA_tree(int root)
{
    discovered.clear(); discovered.resize(N);
    fill(discovered.begin(), discovered.end(), false);
    queue<int> q; 
    q.push(root); 
    discovered[root] = true;
    T[root] = -1; L[root] = 0; W[root] = 0;
    maxi[root][0] = 0; 
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)g[u].size(); i++)
        {
            int v = g[u][i].second;
            ll w = g[u][i].first;
            if(!discovered[v])
            {
                q.push(v); discovered[v] = true;
                T[v] = u;
                L[v] = L[u] + 1;
                W[v] = W[u] + w;
                maxi[v][0] = w; 
            }   
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r,q,x,y;
    
    ll w;
    cin>>N>>r;
    mp=vector<map<int,ll> >(N);
    for(int i=0;i<r;i++)
    {
        cin >> x >> y >> w;
        x--;
        y--;
        edges.push(iii(-w,ii(x,y)));
        mp[x][y]=w;
        mp[y][x]=w;
    }
    ll cost=mst(N);
    
    initialize();
    build_LCA_tree(0);
    initialize_LCA();
    
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        x--;y--;
        cout<<cost-getMaxEdge(x,y)+mp[x][y]<<"\n";
    }
    
    return 0;
}

