#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
#define MAX_N 502
#define MAX (1<<22)+3

ll cost[MAX_N];
 
int main()
{
    fastIO;

    int n,m,x;
    cin>>n>>m;
    if(n<=22)
    {
        ll dp[MAX];
        int mask[MAX_N];
        

        for(int i=0;i<MAX;i++)
            dp[i]=LLONG_MAX;
        
        memset(mask,0,sizeof mask);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                if(x)
                    mask[i]|=(1<<j);
            }
 
            cin>>cost[i];
            dp[mask[i]]=min(dp[mask[i]],cost[i]);
        }
        for(int i=0;i<MAX;i++)
        {
            if(dp[i]!=LLONG_MAX)
            {
                for(int j=0;j<m;j++)
                    dp[i|mask[j]]=min(dp[i|mask[j]],dp[i]+cost[j]);
            }
        }
        cout<<dp[(1<<n)-1]<<"\n";
    }
    else
    {
        bitset<MAX_N> mask[MAX_N];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                if(x)
                    mask[i][j]=1;
            }
            cin>>cost[i];
        }
        ll ans=LLONG_MAX,p;
        bitset<MAX_N> a;
        for(int i=0;i<MAX;i++)
        {
            a.reset();
            p=0LL;
            for(int j=0;j<m;j++)
                if(i&(1<<j))
                {
                    p+=cost[j];
                    a|=mask[j];
                }
            if(a.count()==n)
                ans=min(ans,p);

        }
        cout<<ans<<"\n";

    }
    return 0;
}  