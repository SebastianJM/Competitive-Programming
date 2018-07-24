#include <bits/stdc++.h>

using namespace std;
#define MAX 500004
typedef long long ll;
int t,n,k;

ll solve()
{
    int s=sqrt(n),div;
    ll ans=0LL;
    for(int i=1;i<=s;i++)
    {
        div=n/i;
        if(div*i==n)
        {
            if(div%k!=0)
                ans+=div;
            if(div!=i && i%k!=0)
                ans+=i;
        }
    }
    
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;

        cout<<solve()<<"\n";
    }
    return 0;
}