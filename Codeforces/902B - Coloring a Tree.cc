#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi color;
vi b;
int ans;
void dfs(int x,int from)
{
  if(b[x]!=color[from])
    ans++;
  color[x]=b[x];
  for(int i=0;i<g[x].size();i++)
  {
    if(g[x][i]!=from)
      dfs(g[x][i],x);
  }
  
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,a;
  cin>>n;
  g=vvi(n+1);
  color=b=vi(n+1,0);
  for(int i=1;i<=n-1;i++)
  {
    cin>>a;
    g[a].push_back(i+1);
    g[i+1].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
    cin>>b[i];
  }
  dfs(1,0);
  cout<<ans<<endl;
}