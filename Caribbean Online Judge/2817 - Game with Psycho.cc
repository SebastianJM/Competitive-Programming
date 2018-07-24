#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,ans,s_ant;
    vector<int> v,aux;
    cin>>t;
    while(t--)
    {
      cin>>n;
      ans=0;
      s_ant=0;
      v=vector<int>(n+1);
      for(int i=0;i<n;i++)
          cin>>v[i];
      v[n]=-1;
      while(1)
      {
          aux.clear();
          for(int i=0;i<v.size()-1;i++)
          {
              aux.push_back(v[i]);
              while(v[i]>v[i+1])
                  i++;
          }
          //cout<<aux.size()<<endl;
          if(s_ant==aux.size())
              break;
          ans++;
          v=aux;
          v.push_back(-1);
          s_ant=aux.size();   
      }
      cout<<ans<<"\n";
    }
    return 0;
}