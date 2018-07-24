#include <bits/stdc++.h>

using namespace std;

#define MAX 100004
struct query
{
    int l,r;
    query(){}
} q[MAX];

int main() 
{
    int n,m,k,a[MAX],op;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        a[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>q[i].l>>q[i].r;
        swap(a[q[i].l],a[q[i].r]);
    }
    op=a[k];
    if(op==1)
    {
        for(int i=1;i<=n;i++)
            a[i]=i;
        for(int i=0;i<m;i++)
        {
            if(a[q[i].l]!=1 && a[q[i].r]!=1)
            {
                cout<<i+1<<endl;
                return 0;
            }
            swap(a[q[i].l],a[q[i].r]);
        }
    }
    else
    {
        for(int i=0;i<m;i++)
            if(q[i].l==op || q[i].r==op)
            {
                cout<<i+1<<endl;
                return 0;
            }
    }
    return 0;
}