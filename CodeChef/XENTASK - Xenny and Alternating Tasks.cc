#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 20005
#define VAL 1000005
#define EPS 1e-7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t,n,x[MAX],y[MAX],ans,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
            cin>>y[i];
        ans=INT_MAX;
        c=0;
        for(int i=0;i<n;i++)
            c+=(i&1?y[i]:x[i]); 
        ans=min(ans,c);  
        c=0;
        for(int i=0;i<n;i++)
            c+=(i&1?x[i]:y[i]);
        ans=min(ans,c);
        cout<<ans<<"\n";
    }
    return 0;
}



