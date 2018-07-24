#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

set<int> g[N];
int par[N],sub[N];
char let[N];
int n;

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
    if(p==-1)p=centroid;
    par[centroid]=p;
    for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
    {
        g[*it].erase(centroid);
        decompose(*it,centroid);
    }
    g[centroid].clear();
}

char letter(int x)
{
    if(let[x]!='*')
        return let[x];
    if(par[x]==0)
        return 'A';
    return let[x]=letter(par[x])+1;
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
        g[u].insert(v);
        g[v].insert(u);
    }
    decompose(1,0);
    for(int i=1;i<=n;i++)
        let[i]='*';
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        if(!f)
            cout<<" ";
        f=false;
        cout<<letter(i);
    }
    return 0;
}