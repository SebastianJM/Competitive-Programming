#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 100005
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    fastIO;
    int a[MAX],b[MAX];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    string s;
    int n;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='0')
            a[i]++;
        else
            b[i]++;
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    map<int,int> save;
    save[0]=0;
    int ans=0,x;
    for(int i=1;i<=n;i++)
    {
        x=a[i]-b[i];
        //cout<<x<<" ";
        if(save.find(x)==save.end())
            save[x]=i;
        else
            ans=max(ans,i-save[x]);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}