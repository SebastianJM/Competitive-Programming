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

VVi g;
bool visit[MAX*2];
int col[MAX*2];
int ans;
void dfs(int x,int color,int color_padre)
{
  visit[x]=true;
  col[x]=color;
  ans=max(ans,color);
  int last_son=1;
  for(int i=i;i<g[x].size();i++)
  {
    if(!visit[g[x][i]])
    {
      visit[g[x][i]]=true;
      if(last_son==color||last_son==color_padre)
      last_son++;
      if(last_son==color||last_son==color_padre)
        last_son++;
      dfs(g[x][i],last_son++,color);
    }
  }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  int a,b,n;
  cin>>n;
  memset(visit,false,sizeof visit);
  g=VVi(n+1);
  for(int i=0;i<n-1;i++)
  {
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  ans=0;
  dfs(1,1,0);
  bool f=true;
  cout<<ans<<"\n";
  for(int i=1;i<=n;i++)
  {
  	if(!f)
  		cout<<" ";
  	f=false;
  	cout<<col[i];
  }
    
}