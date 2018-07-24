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
#define MAX 200005
#define VAL 1000005
#define EPS 1e-7

bool visit[MAX];
VVi g,ans;
Vi ar;

void dfs(int x)
{
  visit[x]=true;
  ar.pb(x);
  for(int i=0;i<g[x].size();i++)
  {
    if(!visit[g[x][i]])
    {
      visit[g[x][i]]=true;
      dfs(g[x][i]);
      ar.pb(x);
    }
  }
  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(visit,false,sizeof visit);
  int n,m,k,u,v;
  cin>>n>>m>>k;
  g=VVi(n+1);
  for(int i=0;i<m;i++)
  {
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int maxi=ceil(2.0*(double)(n)/(double)(k));
  dfs(1);
  ans=VVi(k);
  int c=0;
  for(int i=1;i<=k;i++)
  {
    if(c<ar.size())
      while(c<ar.size() && c<maxi*i)
      {
        ans[i-1].pb(ar[c++]);
      }
    else
      ans[i-1].pb(ar[0]);
  }
  for(int i=0;i<k;i++)
  {
    cout<<ans[i].size();
    for(int e=0;e<ans[i].size();e++)
      cout<<" "<<ans[i][e];
    cout<<"\n";
  }
  return 0;
}



