#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define MAX 100005
#define MAX_K 51
 
int main()
{
    fastIO;
    int t,n,k,s,ar[1003];
    bool buy[1003];
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        bool is=true;
        memset(buy,false,sizeof buy);
        memset(ar,0,sizeof ar);
        for(int day=1;day<=s;day++)
        {
            ar[day]=ar[day-1];
            if(day%7==0)
            {
                if(ar[day]<k)
                {
                    for(int past=day-1;past>0;past--)
                        if(!buy[past])
                        {
                            //cout<<"comprando "<<past<<endl;
                            ar[day]+=n;
                            buy[past]=true;
                            break;
                        }
                }
                
                ar[day]-=k;
                if(ar[day]<0)
                {
                    is=false;
                    break;
                }
                continue;
            }
            if(ar[day]<k)
            {
                buy[day]=true;
                ar[day]+=n;
            }
            ar[day]-=k;
            if(ar[day]<0)
            {
                is=false;
                break;
            }
        }
        if(is)
        {
            int ans=0;
            for(int i=1;i<=s;i++)
                if(buy[i])
                    ans++;
            cout<<ans<<"\n";
        }
        else
            cout<<"-1\n";
    }
    return 0;
}   