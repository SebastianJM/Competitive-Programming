#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
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
   
    int a,b,c,d,x,y;
    cin>>a>>b;
    cin>>c>>d;
    if(b&1 && a%2==0 && d%2==0 && c%2==0)
    {
        cout<<"-1\n";
        return 0;  
    }
    if(b%2==0 && a%2==0 && d&1 && c%2==0)
    {
        cout<<"-1\n";
        return 0;  
    }
    int con=0;
    x=b;
    y=d;
    while(con<300000)
    {
        if(x==y)
        {
            cout<<x<<"\n";
            return 0;
        }
        if(x<y)
            x+=a;
        else if(y<x)
            y+=c;
        con++;
    }
        
    
    cout<<"-1\n";
    return 0;       
}