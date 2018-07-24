#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int> > g;
vector<bool> visit;
vector<long long> erdos;
int n,m,a,b;
void bfs()
{
    queue<pair<int,int> > q;
    visit=vector<bool>(n+m,false);
    int x,e;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        x=q.front().first;
        e=q.front().second;
        visit[x]=true;
        q.pop();
        if(x<n)
            erdos[x]=e;
        for(int i=0;i<g[x].size();i++)
            if(!visit[g[x][i]])
            {
                visit[g[x][i]]=true;
                q.push(make_pair(g[x][i],e+(g[x][i]<n?1LL:0LL)));
            }
                
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    g=vector<vector<int> >(n+m+1);
    erdos=vector<long long>(n,-1);
    for(int i=0;i<m;i++)
    {
        cin>>a;
        for(int j=0;j<a;j++)
        {
            cin>>b;
            g[b-1].push_back(i+n);
            g[i+n].push_back(b-1);
        }
    }
    bfs();
    long long d,m,s;
    d=m=s=0;
    for(int i=0;i<n;i++)
    {
        //cout<<erdos[i]<<" ";
        if(erdos[i]>=0)
        {
            s+=erdos[i];
            m=max(m,erdos[i]);
            d++;
        }
    }
    cout<<d<<" "<<m<<" "<<s<<"\n";
    return 0;
} 