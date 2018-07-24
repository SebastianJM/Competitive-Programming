#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 104
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    fastIO;
    int f,c,k;
    cin>>f>>c>>k;
    int m[MAX][MAX],pref[MAX][MAX];
    memset(m,0,sizeof m);
    memset(pref,0,sizeof pref);
    for(int i=1;i<=f;i++)
        for(int j=0;j<c;j++)
            cin>>m[i][j];
    for(int j=0;j<c;j++)
        for(int i=1;i<=f;i++)
        {
            if(m[i][j]==1)
                pref[i][j]++;
            pref[i][j]+=pref[i-1][j];
        }
    int ind,con,rmv=0,ans=0;
    for(int j=0;j<c;j++)
    {
        con=0;
        ind=0;
        for(int i=0;i<=f;i++)
        {
            if(con<pref[i+min(k,f-i)][j]-pref[i][j])
            {
                con=pref[i+min(k,f-i)][j]-pref[i][j];
                ind=i;
                //cout<<j<<" "<<i<<" "<<con<<endl;
            }
        }
        if(con)
        {
            rmv+=pref[ind][j];
            ans+=con;
        }
    }
    cout<<ans<<" "<<rmv<<endl;
    return 0;
}