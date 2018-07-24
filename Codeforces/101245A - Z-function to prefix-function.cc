#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,a=0;
    int f[200005],s[200005];
    memset(s,0,sizeof s);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];
        
    bool fi=true;
    for(int i=1;i<=n;i++)
        if(f[i]>0)
            s[i+f[i]-1]=max(f[i],s[i+f[i]-1]);
    for(int i=n;i>0;i--)
 	{
		a=max(s[i],a);               
        if(a>0)
            s[i]=a--;  
    }
    for(int i=1;i<=n;i++)
    {
        if(!fi)
            cout<<" ";
        fi=false;        
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}