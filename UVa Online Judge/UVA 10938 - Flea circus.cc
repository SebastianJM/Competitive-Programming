#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
typedef vector< pair<int,int> > vii;    
typedef vector<bool> vb;
typedef vector<vii> vvii;   

#define MAX 100005

int n;
int T[MAX];
int P[MAX][17];
int L[MAX];
int W[MAX];
vvii g;
void init()
{
    for(int i=0;i<n;i++)
        for(int j=0;1<<j <n;j++)
            P[i][j]=-1;
    for(int i=0;i<n;i++)
        P[i][0]=T[i];
    for(int j=1; 1<<j <n;j++)
        for(int i=0;i<n;i++)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}

int lca(int p,int q)
{
    int lg;
    if(L[p]<L[q]) swap(p,q);
    for(lg=1;1<<lg<=L[p];lg++); lg--;
    for(int i=lg;i>=0;i--)
        if(L[p]-L[q]>=(1<<i))
            p=P[p][i];
    if(p==q)
        return p;
    for(int i=lg;i>=0;i--)
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i];
    return P[p][0];
}

vb disc;
void build(int s)
{
    queue<int> q;q.push(s);
    disc=vb(n,false);
    disc[s]=true;
    T[s]=-1; L[s]=0;W[s]=0;
    while(!q.empty())
    {
        int v=q.front();q.pop();
        for(int i=0;i<(int)g[v].size();i++)
        {
            int u=g[v][i].second;
            int w=g[v][i].first;
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

int dist(int p,int q)
{
    return W[p]+W[q]-W[lca(p,q)]*2;
}

int main()
{
   int u,v,t;
   while(1)
   {
        cin>>n;
        if(n==0)
            return 0;
        g=vvii(n);
        for(int i=0;i<n-1;i++)
        {
            cin>>u>>v;
            u--;v--;
            g[u].push_back(pi(1,v));
            g[v].push_back(pi(1,u));
        }
        build(0);
        init();
        
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>u>>v;
            u--;v--;
            int h=dist(u,v);
            
            if(h%2==0)
            {
                int m=h/2;
                int maxi=W[u]>W[v]?u:v;
                while(m)
                {
                    maxi=T[maxi];
                    m--;
                }
                cout<<"The fleas meet at "<<maxi+1<<".\n";
            }
            else
            {
                int m=(h-1)/2;
                int maxi=W[u]>W[v]?u:v;
                while(m)
                {
                    maxi=T[maxi];
                    m--;
                }
                int ss=T[maxi];
                cout<<"The fleas jump forever between "<<min(maxi,ss)+1<<" and "<<max(maxi,ss)+1<<".\n";
            }
        }
   }
   
    

    return 0;
}
