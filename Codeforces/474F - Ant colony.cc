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
#define MAX 100005
#define INF DBL_MAX
#define EPS 1e-7

int t[MAX*2];
int n;

int gcd(int a, int b) 
{ 
    return (b == 0) ? a : gcd(b, a % b); 
}

void build()
{
    for(int i = n - 1; i > 0; i--) 
        t[i] = gcd(t[i << 1],t[i << 1 | 1]); 
}

int query(int l, int r) 
{
    int ans = t[n+l];
    for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if( l & 1 ) ans = gcd(ans,t[l]);
        if(!(r & 1)) ans = gcd(t[r],ans); 
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q,l,r,a;
    Pii ar[MAX];
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>t[n+i];
        ar[i-1].first=t[n+i];
        ar[i-1].second=i;
    }
    build();
    
    cin>>q;
    sort(ar,ar+n);

    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        a=query(l,r);
        cout<<r-l+1-(upper_bound(ar,ar+n,Pii(a,r))-lower_bound(ar,ar+n,Pii(a,l)))<<"\n";
    }
    return 0;   
}

