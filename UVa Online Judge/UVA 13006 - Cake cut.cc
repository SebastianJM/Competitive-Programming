#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 100002

ll x[MAX],y[MAX];

inline ll cross(ll a,ll b) { return x[a] * y[b] - x[b] * y[a]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll area;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        area=0;
        for(int i=0;i<n;i++)
            area+=cross(i,(i+1)%n);
        area=llabs(area);
        int ref=1;
        ll ac=0,xx,ans=0,futuro,actual,ansa,ansb;
        for(int i=0;i<n;i++)
        {
            while(ref<=i+2)
        	{
                ac+=cross((ref-1)%n,ref%n);
                ref++;
        	}
            ac+=cross((ref-1)%n,i);
            actual=abs(abs(ac)-(area-abs(ac)));
            while(1)
            {
                futuro=ac-cross((ref-1)%n,i)+cross((ref-1)%n,ref%n)+cross(ref%n,i);
                if(llabs(llabs(futuro)-(area-llabs(futuro)))>=llabs(llabs(ac)-(area-llabs(ac))))
                    break;
                ac=futuro;
                ref++;
            }
            xx=llabs(llabs(ac)-(area-llabs(ac)));
            if(ans<=xx)
            {
                ans=xx;
                ansa=max(llabs(ac),area-llabs(ac));
                ansb=min(llabs(ac),area-llabs(ac));
            }
            ac-=(cross(i,(i+1)%n)+cross((ref-1)%n,i));
        }
        cout<<ansa<<" "<<ansb<<"\n";
    }
  
    return 0;
}
