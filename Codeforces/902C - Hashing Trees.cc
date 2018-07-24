#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi par;
vi h;
int con,n;
void dfs(int alt,int ac,int root)
{
  if(alt>n)
    return;
  
  for(int i=ac;i<ac+h[alt];i++)
  {
    par[i]=root;
    g[alt].push_back(i);
  }
    
  
  root=ac;  
  ac+=h[alt];
  dfs(alt+1,ac,root);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a,s=0;
  cin>>n;
  h=vi(n+1);
  for(int i=0;i<=n;i++)
  {
    cin>>h[i];
    s+=h[i];
  }


    bool ans=false;
    con=1;
    par=vi(s+1,0);
    g=vvi(n+1);
    dfs(0,1,0);
    for(int i=1;i<=n;i++)
      if(h[i]>1 && h[i-1]>1)
      {
        ans=true;
        cout<<"ambiguous\n";
        for(int i=1;i<=s;i++)
        {
          if(i>1)
            cout<<" ";
          cout<<par[i];
        }
        cout<<endl;
        par[g[i][0]]=g[i-1][1];
        for(int i=1;i<=s;i++)
        {
          if(i>1)
            cout<<" ";
          cout<<par[i];
        }
        cout<<endl;
        break;
      }
    if(!ans)
   
    cout<<"perfect\n";



  return 0;
  
}