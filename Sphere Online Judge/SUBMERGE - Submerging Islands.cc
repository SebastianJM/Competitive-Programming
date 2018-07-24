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
const int MAX = 10005; // Max number of nodes
 
int n;
vvi g;
int dfs_cont; // Counter
vi dfs_num; // Value of dfs_cont when a node is visited for the first time
vi dfs_low; // Lowest dfs_num reachable from a node
int dfs_root; // dfs_visit initial node
int children; // Number of neighbors of root node
// Information about Articulation Point (AP)
vb isAP; // isAP[i] : check if the node is an AP
void dfs_visit(int v, int p) // v: Current node, p: Previous node
{
    dfs_num[v] = dfs_low[v] = dfs_cont++; // First visit to the node v
    for(int i = 0; i < (int)g[v].size(); i++) // For each neighbor of v..
    {
        int u = g[v][i]; // Neighbor u. Edge v -> u
        if(dfs_num[u] < 0) // If the node u has not been discovered..
        {
            if(v == dfs_root) // If node v is the root..
                children++; // Count the number of children
            dfs_visit(u, v); // Visit node u
            if(dfs_low[u] >= dfs_num[v]) // If the only way to reach u is through v
                isAP[v] = true; // Node v is an AP
            dfs_low[v] = min(dfs_low[v], dfs_low[u]); // Update dfs_low
        }
        else if(u != p) // If the node u is not the predecessor..
            dfs_low[v] = min(dfs_low[v], dfs_num[u]); // Update dfs_low
    }
}
void dfs()
{
    dfs_cont = 0; // Counter starts at 0
    dfs_num = vi(n, -1); // No node has been discovered
    dfs_low = vi(n, INF); // The nodes are unreachable
    isAP = vb(n, false); // No node is an AP at the beginning
    for(int i = 0; i < n; i++) // For each node i..
        if(dfs_num[i] < 0) // If the node i has not been discovered..
        {
            dfs_root = i; // Store information of root node
            children = 0; // Node starts with 0 children
            dfs_visit(i, -1); // Visit the connected component
            isAP[i] = (children > 1); // The root is an AP if it has > 1 child
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,a,b;
    while(1)
    {
        cin>>n>>m;
        if(!n && !m)
            break;
        g=vvi(n);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs();
        int ans=0;
        for(int i=0;i<n;i++)
            if(isAP[i])
                ans++;
        cout<<ans<<"\n";
    }
    return 0;
} 