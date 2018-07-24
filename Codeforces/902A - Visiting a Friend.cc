#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m,v[102],a,b;
  memset(v,0,sizeof v);
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    cin>>a>>b;
    for(int j=a;j<b;j++)
      v[j]++;
  }
  bool ans=true;
  for(int i=0;i<m;i++)
    if(v[i]==0)
      ans=false;
  if(ans)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}