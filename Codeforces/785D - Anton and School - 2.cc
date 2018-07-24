#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> Pii;
typedef pair<ll,Pii> PiPii;
typedef vector<PiPii> VPiPii;
typedef vector<VPiPii> VVPiPii;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;


#define pb(x) push_back(x) 
#define MAX 200004
#define INF INT_MAX
#define EPS 1e-7
#define MOD 1000000007

PiPii extendedEuclid(ll a, ll b)
{
    if(b == 0) 
        return PiPii(a, Pii(1, 0)); 
    PiPii p = extendedEuclid(b, a % b);
    ll x = p.second.first, y = p.second.second;
    return PiPii(p.first, Pii(y, x - (a / b) * y));
}

ll inversoModular(ll a)
{
    return (extendedEuclid(a, MOD).second.first + MOD) % MOD;
}

ll multMod(ll a,ll b)
{
	return (a*b)%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    ll ac[MAX],fact[MAX];
    memset(ac,0,sizeof ac);
    cin>>s;
    fact[0]=1LL;
    for(int i=1;i<MAX;i++)
        fact[i]=(fact[i-1]*i)%MOD;

    for(int i=1;i<s.size();i++)
    {
        if(s[i]==')')
            ac[i]=1LL;
        ac[i]+=ac[i-1];
    }
    ll ans=0,izq=0,der;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            izq++;
            der=ac[s.size()-1]-ac[i];
            ans=(ans+multMod(fact[(izq-1+der)%MOD],inversoModular(multMod(fact[der-1LL],fact[izq]))))%MOD;
        }
    } 
    cout<<ans<<"\n";
    return 0;       
}