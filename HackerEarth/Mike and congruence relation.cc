#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define MAX 500005

int main()
{
    fastIO;
    ll n,k,d,r,ans=0LL;
    cin>>n>>k;
    n--;
    d=n/k;
    r=n%k;
    ans+=(r+1)*(d+1)*(d)/2;
    ans+=(k-(r+1))*(d)*(d-1)/2;
    cout<<ans<<endl;

    return 0;
}  