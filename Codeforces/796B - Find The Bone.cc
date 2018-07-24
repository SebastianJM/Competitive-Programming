#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool hole[2000004];
    memset(hole,false,sizeof hole);
    int n,m,a,k,ac,x,y;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        hole[a]=true;
    }
    ac=1;
    if(hole[1])
    {
        cout<<1<<endl;
        return 0;
    }
        
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        if(ac==x || ac==y)
        {
            if(ac==x)
            {
                ac=y;
                if(hole[y])
                {
                    cout<<y<<endl;
                    return 0;
                }
            }
            else
            {
                ac=x;
                if(hole[x])
                {
                    cout<<x<<endl;
                    return 0;
                }
            }
            
        }
    }
    cout<<ac<<endl;
    return 0;
}