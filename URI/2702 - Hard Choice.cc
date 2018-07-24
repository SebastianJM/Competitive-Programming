#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    int ans=0;
    if(x>a)
        ans+=x-a;
    if(y>b)
        ans+=y-b;
    if(z>c)
        ans+=z-c;
    cout<<ans<<endl;
    return 0;
}