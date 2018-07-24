#include <bits/stdc++.h>
using namespace std;

#define MAX 21

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
vvi g;
vi match;
vb visit;
int n=1000;
inline int augment(int v)
{
    if(visit[v])
        return 0;
    visit[v] = true;
    for(int i = 0; i < (int)g[v].size(); i++)
    {
        int u = g[v][i];
        if(match[u] == -1 || augment(match[u]))
        {
            match[u] = v;
            return 1;
        }
    }
    return 0;
}
int mcbm(int left) // left: Num of vertex on left
{
    int ans = 0;
    match = vi(n, -1);
    for(int i = 0; i < left; i++)
    {
        visit = vb(left, false);
        ans += augment(i);
    }
    return ans;
}
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char M[MAX][MAX];
    int index[MAX][MAX],can[MAX][MAX];
    int f,c;
    cin>>f>>c;
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++)
            cin>>M[i][j];
    int a,b,qa,qb;
    qa=qb=0;
    a=2;
    b=502;
    g=vvi(1000);
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            can[i][j]=(M[i][j]=='o'?1:2);
            if(can[i][j]&1)
                qb++;
            qa+=can[i][j];
            if(((i&1) && (j&1))||(!(i&1) && !(j&1)))
            {
                index[i][j]=a;
                a+=2;
            }
            else
            {
                index[i][j]=b;
                b+=2;
            }
        }
    }
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++)
        {
            for(int z=0;z<4;z++)
            {
                if(i+y[z]>=0 && i+y[z]<f && j+x[z]>=0 && j+x[z]<c)
                {
                    g[index[i][j]-1].push_back(index[i+y[z]][j+x[z]]-1);
                    if(can[i+y[z]][j+x[z]]==2)
                        g[index[i][j]-1].push_back(index[i+y[z]][j+x[z]]-2);
                    if(can[i][j]==2)
                    {
                        g[index[i][j]-2].push_back(index[i+y[z]][j+x[z]]-1);
                        if(can[i+y[z]][j+x[z]]==2)
                            g[index[i][j]-2].push_back(index[i+y[z]][j+x[z]]-2);
                    }
                }
            }
        }
    if(qb&1)
    {
        cout<<"N\n";
        return 0;
    }
    int ans=mcbm(500);
    if(ans==qa/2)
        cout<<"Y\n";
    else
        cout<<"N\n";
    return 0;
}