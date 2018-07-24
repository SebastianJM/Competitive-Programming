#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = 200000000;
const int MAX = 26;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b,s,d;
    bool is;
    int t,n,u,c=1,ans;
    ll x,y;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ans=0;
        n=(int)(s.size());
        if(n==1)
        {
            cout<<"Case #"<<c++<<": "<<1<<"\n";
            continue;
        }
        
        for(int i=0;i<(n>>1);i++)
        {
            a=s[i];
            b=s[n-1-i];
            x=(long long)(s[i]);
            y=(long long)(s[n-1-i]);
            u=i;
            is=false;
            while(i<(n>>1))
            {
                if(s[u]==s[n-1-i] && x==y && a==b)
                {
                    is=true;
                    break;
                }
                i++;
                a.push_back(s[i]);
                d=s[n-i-1];
                b.insert(0,d);
                x+=(long long)(s[i]);
                y+=(long long)(s[n-1-i]);
            }
            //cout<<i<<endl;
            if(is)
            {
                if(i==(n>>1)-1 && n&1)
                    ans+=3;
                else
                    ans+=2;
                
            }
                
            else
                ans++;
            
                
        }
        cout<<"Case #"<<c++<<": "<<ans<<"\n";
    }
    return 0;
}