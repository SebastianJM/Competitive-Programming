#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,v[200];
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=INF;
    for(int i=m-2,c=1;i>=0;i--,c++)
        if(v[i]>0 && v[i]<=k)
        {
            
             ans=c*10;
             break;
        }
    for(int i=m,c=1;i<n;i++,c++)   
        if(v[i]>0 && v[i]<=k)
        {
            
            ans=min(ans,c*10);
            break;
        }
    cout<<ans<<endl;
    return 0;
}