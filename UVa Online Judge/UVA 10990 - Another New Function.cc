#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ull> ii;
typedef pair<ull,ii> iii;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
#define PI  (2.0*acos(0.0))
#define MAX 2000004
#define MOD 1000000007
#define EPS 1e-7

int f_phi(int n) 
{
    int result = n;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) 
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    if(n > 1)
        result -= result / n;
    return result;
}
int main() {
    int n, m,phi[MAX];
    ull pre[MAX];
    phi[1]=0;
    for(int i=2;i<MAX;i++)
        phi[i]=phi[f_phi(i)]+1;
    pre[1]=0;
    for(int i=2;i<MAX;i++)
        pre[i]=pre[i-1]+phi[i];
    int te;
    cin>>te;
    while(te--)
    {
        cin>>m>>n;
        cout<<pre[n]-pre[m-1]<<"\n";
    }
    return 0;
}
// END CUT