#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x) 
#define N 100005
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
int n;
vector<int> v;
vector<int> switchVector(vector<int> ar,int from,int to)
{
    while(from<to)
    {
        swap(ar[from++],ar[to--]);
    }
    return ar;
}
int minSteps()
{
    queue<pair<vector<int>,int>> q;
    q.push(make_pair(v,0));
    set<vector<int>> s;
    vector<int> aux,x2;
    int step;
    while(!q.empty())
    {
        aux=q.front().first;
        step=q.front().second;
        q.pop();
        bool inc=true;
        for(int i=1;i<n;i++)
            if(aux[i]<aux[i-1])
            {
                inc=false;
                break;
            }
        if(inc)
            return step;
       
        for(int j=1;j<n;j++)
        {
            x2=switchVector(aux,0,j);
            if(s.find(x2)==s.end())
            {
                q.push(make_pair(x2,step+1));
                s.insert(x2);
            }
        }
    }
    return 10000;
}
int main() 
{
    fastIO;
    
    cin>>n;
    v=vector<int>(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<minSteps()<<"\n";
    return 0;
}