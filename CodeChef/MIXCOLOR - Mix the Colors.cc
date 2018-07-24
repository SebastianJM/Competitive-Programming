#include <bits/stdc++.h>
using namespace std;
 
#define N 100005
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() 
{
    fastIO;
    int t,n,a,ans;
    set<int> s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        s.clear();
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(s.find(a)!=s.end())
                ans++;
            s.insert(a);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
 