#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = 200000000;
const int MAX = 26;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t,k,c=1;
    ll ans,v[104],r[103];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v,v+n);
        ans=0LL;
        for(int i=0;i<n-1;i++)
        {
            r[i]=v[i+1]-v[i];
            ans+=r[i];
        }
        sort(r,r+(n-1));
  
        for(int i=0;i<k-1;i++)
            ans-=r[n-2-i];
        cout<<"Case #"<<c++<<": "<<ans<<"\n";
    }
    return 0;
}
