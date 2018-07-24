#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
#define MAX 200010
#define EPS 1e-7
 
bool equals(double a,double b)
{
    if(fabs(a-b)<=EPS)
        return true;
    return false;
}
 
int main()
{
    fastIO;
    int te;
    cin>>te;
    double t,ans;
    int car,dis,sep,n;
 
    cout<<fixed<<setprecision(9);
    while(te--)
    {
        cin>>n;
        ans=0.0;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            ans=max(ans,t);
        }
        cin>>car>>dis>>sep;
 
        cout<<(ans)*(car-1.0)<<"\n";
    }
    return 0;
}  