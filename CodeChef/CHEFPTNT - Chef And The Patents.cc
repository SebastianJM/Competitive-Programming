#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
 
const int MAX = 100000;
 
int main()
{
    fastIO;
    int te;
    ll n,m,x,k,ev,od;
    string s;
    cin>>te;
    while(te--)
    {
        cin>>n>>m>>x>>k;
        cin>>s;
        if(x==0||m==0)
        {
            cout<<"no\n";
            continue;
        }
        ev=od=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='E')
                ev++;
            else
                od++;
 
        for(int month=1;month<=m;month++)
        {
        	if(month&1)
        	{
        		n-=min(od,x);
        		od-=min(od,x);
        	}
        	else
        	{
        		n-=min(ev,x);
        		ev-=min(ev,x);
        	}
        }
        
        if(n<=0)
            cout<<"yes\n";
        else
            cout<<"no\n";
 
    }
    return 0;
}   