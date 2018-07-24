#include <bits/stdc++.h>
using namespace std;
 
#define N 100005
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() 
{
    //fastIO;
    int t,n;
    double price,quan,disc,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0.0;
        for(int i=0;i<n;i++)
        {
            cin>>price>>quan>>disc;
            double np=price+price*(disc/100.0);
            double d=np-np*(disc/100.0);
            ans+=quan*(d<price?(price-d):0.0);
        }
        printf("%.7lf\n",ans);
    }
    return 0;
}
 