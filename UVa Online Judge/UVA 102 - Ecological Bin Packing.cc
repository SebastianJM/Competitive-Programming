#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
  int B[3],G[3],C[3];
  while(cin>>B[0]>>G[0]>>C[0]>>B[1]>>G[1]>>C[1]>>B[2]>>G[2]>>C[2])
  {
    int ans=2147483647;
    int up=B[1]+B[2]+C[0]+C[2]+G[0]+G[1];
    if(up<ans)
    {
      ans=up;
      s="BCG";
    }
    up=B[1]+B[2]+G[0]+G[2]+C[0]+C[1];
    if(up<ans)
    {
      ans=up;
      s="BGC";
    }
    up=C[1]+C[2]+B[0]+B[2]+G[0]+G[1];
    if(up<ans)
    {
      ans=up;
      s="CBG";
    }
    up=C[1]+C[2]+G[0]+G[2]+B[0]+B[1];
    if(up<ans)
    {
      ans=up;
      s="CGB";
    }
    up=G[1]+G[2]+B[0]+B[2]+C[0]+C[1];
    if(up<ans)
    {
      ans=up;
      s="GBC";
    }
    up=G[1]+G[2]+C[0]+C[2]+B[0]+B[1];
    
    if(up<ans)
    {
      ans=up;
      s="GCB";
    }
    cout<<s<<" "<<ans<<endl;
  }
  return 0;
}