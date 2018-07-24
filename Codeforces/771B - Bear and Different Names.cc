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
#define MAX 200004
#define INF INT_MAX
#define EPS 1e-7
#define MOD 1000000007


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int,string> mp;
    mp[0]="Aa";
    mp[1]="Ab";
    mp[2]="Ac";
    mp[3]="Ad";
    mp[4]="Ae";
    mp[5]="Af";
    mp[6]="Ag";
    mp[7]="Ah";
    mp[8]="Ai";
    mp[9]="Aj";
    mp[10]="Ak";
    mp[11]="Al";
    mp[12]="Am";
    mp[13]="An";
    mp[14]="Ao";
    mp[15]="Ap";
    mp[16]="Aq";
    mp[17]="Ar";
    mp[18]="As";
    mp[19]="At";
    mp[20]="Au";
    mp[21]="Av";
    mp[22]="Aw";
    mp[23]="Ax";
    mp[24]="Ay";
    mp[25]="Az";
    mp[26]="Ba";
    mp[27]="Bb";
    mp[28]="Bc";
    mp[29]="Bd";
    mp[30]="Be";
    mp[31]="Bf";
    mp[32]="Bg";
    mp[33]="Bh";
    mp[34]="Bi";
    mp[35]="Bj";
    mp[36]="Bk";
    mp[37]="Bl";
    mp[38]="Bm";
    mp[39]="Bn";
    mp[40]="Bo";
    mp[41]="Bp";
    mp[42]="Bq";
    mp[43]="Br";
    mp[44]="Bs";
    mp[45]="Bt";
    mp[46]="Bu";
    mp[47]="Bv";
    mp[48]="Bw";
    mp[49]="Bx";
    mp[50]="By";

    int n,k,act=0;
    string op;
    cin>>n>>k;
    vector<string> ans;
    cin>>op;
    if(op=="NO")
    {
        for(int i=0;i<k-1;i++)
            ans.pb(mp[act++]);
        ans.pb(ans[0]);
    }
    else
        for(int i=0;i<k;i++)
            ans.pb(mp[act++]);
        
    for(int i=1;i<n-k+1;i++)
    {
        cin>>op;
        if(op=="NO")
            ans.pb(ans[i]);
        else
            ans.pb(mp[act++]);
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;       
}