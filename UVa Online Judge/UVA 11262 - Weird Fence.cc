#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int n;
vi match;
vb visit;
vvi g;
int augment(int v)
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
int mcbm(int left)
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
double dist(pii a,pii b)
{
    return hypot(a.first-b.first,a.second-b.second);
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,k,x,y;
    string s;
    vector<pii > a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        a=vector<pii >();
        b=vector<pii >();
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>s;
            if(s[0]=='b')
                b.push_back(make_pair(x,y));
            else
                a.push_back(make_pair(x,y));
        }
        int lo = 0, hi = 3000,len=a.size();
        bool isans=false;
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;
            g=vvi(n);
            for(int i=0;i<len;i++)
                for(int j=0;j<b.size();j++)
                    if(dist(a[i],b[j])<=(double)mid)
                    {
                        g[i].push_back(len+j);
                        g[len+j].push_back(i);
                    }
            if(mcbm(len)>=k) 
            {
                isans=true;
                hi = mid;
            }
                
            else 
                lo = mid + 1;
        }
        if(isans)
            cout<<lo<<"\n";
        else
            cout<<"Impossible\n";
    }
    return 0;
}