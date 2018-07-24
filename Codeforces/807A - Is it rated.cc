#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v[5000],x[5000],y[5000];
    memset(v,0,sizeof v);
    int n,xx,yy;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]!=y[i])
        {
                cout<<"rated"<<endl;
            return 0;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(x[i]>x[i-1])
        {
            cout<<"unrated"<<endl;
            return 0;
        }
    }
    cout<<"maybe"<<endl;
    return 0;
}