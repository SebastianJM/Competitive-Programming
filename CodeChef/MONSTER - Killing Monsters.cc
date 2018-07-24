#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define MAX_VAL 1000000003
#define MAX_N (1<<17)+3
#define MASK (1<<17)-1
#define MAX_Q (1<<18)+3
#define MAX_BIT 18

int h[MAX_N],dp[MAX_Q],query[MAX_Q][2],ans[MAX_Q];

int main()
{
    fastIO;
    int n,q;
    cin>>n;  
    for(int i=0;i<n;i++)
        cin>>h[i];
    cin>>q;
    memset(ans,0,sizeof ans);
    for(int i=0;i<q;i++)
    {
        cin>>query[i][0]>>query[i][1];
        query[i][0]&=MASK;
    }
    int sq=sqrt(q);
    
    for(int block=0;block<=sq;block++)
    {
        memset(dp,0,sizeof dp);
      
        for(int b=block*sq;b<(block+1)*sq && b<q;b++)
            dp[query[b][0]]+=query[b][1];
            
 
        for(int bit=0;bit<MAX_BIT;bit++)
            for(int mask=MASK;mask>=0;mask--)
                if(!(mask&(1<<bit)))
                {
                    dp[mask]+=dp[mask^(1<<bit)];
                    dp[mask]=min(dp[mask],MAX_VAL);
                }   
                              
        for(int i=0;i<n;i++)
        {
            if(h[i]<=0)
                continue;
            h[i]-=dp[i];
            if(h[i]<=0)
            {
                int suma=0;
                for(int b=block*sq;b<(block+1)*sq && b<q;b++)
                {
                    if((query[b][0]&i)==i)
                        suma+=query[b][1];
                    if((dp[i]+h[i])-suma<=0)
                    {
                        ans[b]++;
                        break;
                    }
                }
            }        
        }
        
    }
    for(int i=0;i<q;i++)
    {
        n-=ans[i];
        cout<<n<<"\n";
    }

    return 0;
}  
