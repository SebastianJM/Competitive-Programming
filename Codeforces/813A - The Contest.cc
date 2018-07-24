#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 102
int main() 
{
    fastIO;
    int n,q,s,a;
    s=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s+=a;
    }
    bool ans=false;
    int l,r,res;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        if(!ans)
        {
            if(l<=s && r>=s)
            {
                res=s;
                ans=true;
            }
            else if(l>=s)
            {
                res=l;
                ans=true;
            }
        }
    }
    if(ans)
        cout<<res<<endl;
    else
        cout<<-1<<endl;
    return 0;
}