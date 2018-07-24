#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 102
typedef  long long ull;

ull expo(ull n,int t)
{
    ull ans=1;
    for(int i=0;i<t;i++)
        ans*=n;
    return ans;
}
int main() 
{
    //fastIO;
    ull x,y,l,r;
    cin>>x>>y>>l>>r;
    vector<ull> vx,vy;

    vx.push_back(1);
    vy.push_back(1);

    for(int i=1;i<10000;i++)
    {
        ull a=expo(x,i-1);
        //cout<<a<<endl;

        if(a<=((r/x)+1))
            vx.push_back(a*x);
        else
            break;

    }
    for(int i=1;i<10000;i++)
    {
        ull a=expo(y,i-1);

        if(a<=((r/y)+1))
            vy.push_back(a*y);
        else
            break;

    }
    /*for(int i=0;i<vx.size();i++)
        cout<<vx[i]<<" ";
    cout<<endl;
    for(int i=0;i<vy.size();i++)
        cout<<vy[i]<<" ";
    cout<<endl;*/
    vector<ull> poss;

    for(int i=0;i<vx.size();i++)
    {
        for(int j=0;j<vy.size();j++)
        {
            if((vx[i]+vy[j]>=l))
            {
                if(vx[i]+vy[j]<=r)
                    poss.push_back(vx[i]+vy[j]);
                else
                    break;
            }
        }
    }
    ull ans=0;
    if(poss.size()>0)
    {
        sort(poss.begin(),poss.end());
        ans=max(ans,poss[0]-l);
        for(int i=1;i<poss.size();i++)
            if(poss[i]<=r)
                ans=max(ans,poss[i]-poss[i-1]-1);
        ans=max(ans,r-poss[poss.size()-1]);
    }
    else
        ans=r-l+1;
    cout<<ans<<endl;

    return 0;
}