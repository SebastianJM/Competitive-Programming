#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll x,y,a,b,ans,g,z;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>t;
    for(int e=0;e<t;e++)
    {
        cin>>x>>y>>a>>b;
        if((a==b&&y!=x)||(a==0&&x!=0))
        {
            cout<<-1<<"\n";
            continue;
        }
        
        ll lo = 0, hi = 10000000000;
		while(lo < hi)
		{
			ll mid = lo + (hi-lo)/2; 
			if(0<=a*mid-x && a*mid-x<=b*mid-y) 
			hi = mid;
			else 
			lo = mid + 1; 
		}

        cout<<lo*b-y<<"\n";
    }
    
    
    return 0;
}