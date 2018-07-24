#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pllll;
typedef pair<int,Pii> PiPii;
typedef vector<PiPii> VPiPii;
typedef vector<VPiPii> VVPiPii;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 1004
#define INF INT_MAX
#define EPS 1e-7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t,a,b,c,con,ans[MAX],val[MAX];
    cin>>n;
    con=n-1;
    for(int i=1;i<=n;i++)
        ans[i]=INF;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        if(ans[b]==INF)
            con--;
        ans[b]=min(ans[b],c);
    }
    if(con)
        cout<<-1<<"\n";
    else
    {
        con=0;
        for(int i=1;i<=n;i++)
            con+=(ans[i]==INF?0:ans[i]);
        cout<<con<<"\n";
    }
    return 0;   
}

