#include <bits/stdc++.h>
using namespace std;
 
#define N 100005
#define A 100005
#define BLOCK 1000 // ~sqrt(N)
#define BITS 31
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int a[N], ans[N],bts[BITS];
 
struct node 
{
    int L, R, i, block;
    node(){}
};
node q[N];
inline bool cmp(const node &x,const node &y) 
{
    if(x.block != y.block) 
        return x.block < y.block;
    return x.R < y.R;
}
inline void add(int position) 
{
    for(int i=0;i<BITS;i++)
        bts[i]+=(a[position]&(1<<i)?1:-1);
}
inline void remove(int position)
{
    for(int i=0;i<BITS;i++)
        bts[i]+=(a[position]&(1<<i)?-1:1);
}
int main() 
{
    fastIO;
    int n,m,p=(1<<31)-1,answer;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]^=p;
    }
 
    for(int i=0; i<m; i++) 
    {
        cin>>q[i].L>>q[i].R;
        q[i].L--; q[i].R--;
        q[i].i = i;
        q[i].block=q[i].L/ BLOCK;
    }
    sort(q, q + m, cmp);
    int currentL = 0, currentR = 0,L,R;
    for(int i=0; i<m; i++) 
    {       
        L = q[i].L, R = q[i].R;
        while(currentL < L) 
            remove(currentL++);
 
        while(currentL > L) 
            add(--currentL);
 
        while(currentR <= R) 
            add(currentR++);
 
        while(currentR > R+1) 
            remove(--currentR);
        answer=0;
        for(int i=0;i<BITS;i++)
            if(bts[i]>0)
                answer|=(1<<i);
        ans[q[i].i] = answer;
    }
    for(int i=0; i<m; i++)
        cout<<ans[i]<<"\n";
}
 
 