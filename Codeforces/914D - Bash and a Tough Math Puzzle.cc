#include<bits/stdc++.h>
 
using namespace std;
 
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 500005

int t[MAX*2],n,x;

void build()
{
    for(int i=n-1;i>0;i--)
        t[i]=__gcd(t[i<<1],t[(i<<1)|1]);
}
void update(int i,int val)
{
    for(t[i+=n]=val;i>>=1;)
        t[i]=__gcd(t[i<<1],t[(i<<1)|1]);
}
int decomp(int i)
{
    if(i>=n)
        return t[i]%x!=0;
    int l=t[i<<1]%x;
    int r=t[i<<1|1]%x;
    if(l && r)
        return 2;
    else if(l)
        return decomp(i<<1);
    else
        return decomp(i<<1|1);
}
bool query(int l,int r)
{
    int con=0;
    for(l+=n,r+=n;l<=r;l=(l+1)>>1,r=(r-1)>>1)
    {
        if(l&1)
        {
            if(t[l]%x!=0)
                con+=decomp(l);
            if(con>=2)
                return false;
        }
        if(!(r&1))
        {
            if(t[r]%x!=0)
                con+=decomp(r);
            if(con>=2)
                return false;
        }
    }
    return true;
}
int main()
{
    fastIO;
    cin>>n;
    memset(t,0,sizeof t);
    for(int i=0;i<n;i++)
        cin>>t[i+n];
    build();
    int q,ty,l,r;
    cin>>q;
    while(q--)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>l>>r>>x;
            if(query(l-1,r-1))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            cin>>l>>r;
            update(l-1,r);
        }
    }
    return 0;
}  