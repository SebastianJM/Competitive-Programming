
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MAX 100004
int a[MAX],b[MAX],t[MAX];
bool mark[MAX];
vi pset;
int nSets; 
void init(int n)
{
    nSets = n;
    pset = vi(n, 0); 
    for(int i = 0; i < n; i++) 
        pset[i] = i; 
}
int findSet(int i) 
{
    return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j); 
}
void unionSet(int i, int j) 
{
    if(!isSameSet(i, j)) 
    {
        nSets--; 
        pset[findSet(i)] = findSet(j);
    }
}

int main() 
{
    int n,m,q;

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
        
    cin>>q;
    memset(mark,false,sizeof mark);
    for(int i=0;i<q;i++)
    {
        cin>>t[i];
        t[i]--;
        mark[t[i]]=true;
    }
    init(n);
    for(int i=0;i<m;i++)
    {
        if(!mark[i])
            unionSet(a[i],b[i]);
    }
    int ans[MAX];
    for(int i=q-1;i>=0;i--)
    {
        ans[i]=nSets;
        unionSet(a[t[i]],b[t[i]]);
    }
    for(int i=0;i<q;i++)
    {
        if(i)
            cout<<" ";
        cout<<ans[i];
    }
        
    return 0;
}