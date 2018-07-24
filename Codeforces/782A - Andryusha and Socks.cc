#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,a;
  set<int> s;
  set<int>::iterator it;
  cin>>n;
  int ans=0;
  for(int i=0;i<2*n;i++)
  {
      cin>>a;
      it=s.find(a);
      ans=max(ans,(int)s.size());
      if(it!=s.end())
        s.erase(it);
      else
        s.insert(a);
      ans=max(ans,(int)s.size());
  }
  cout<<ans<<endl;
}