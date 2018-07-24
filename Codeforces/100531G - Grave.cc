#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("grave.in","r",stdin);
    freopen("grave.out","w",stdout);
    int x1,x2,y1,y2;
    int a,b,x,y,h,v;
    cin>>x1>>y1>>x2>>y2;
    cin>>a>>b>>x>>y;
    h=max(a-x1,x2-x);
    v=max(b-y1,y2-y);
    cin>>a>>b;
    if(a<=h && b<=y2-y1)
        cout<<"Yes\n";
    else if(b<=v && a<=x2-x1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}