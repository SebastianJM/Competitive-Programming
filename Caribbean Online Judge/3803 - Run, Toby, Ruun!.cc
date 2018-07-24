#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int t,n,v[100005],con[1000005],ans,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(con,0,sizeof con);
        for(int i=0;i<n;i++)
            cin>>v[i];
        ans=0;
        c=0;
        for(int i=0,e=0;i<n;i++)
        {
            con[v[i]]++;
            if(con[v[i]]>1)
            {
                while(con[v[i]]>1)
                {
                    con[v[e]]--;
                    if(con[v[e++]]==0)
                        c--;
                }
            }
            else c++;
            ans=max(ans,c);
        }
        cout<<ans<<"\n";
    }
	return 0;
}