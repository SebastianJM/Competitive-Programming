#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi pset; // pset[i]: Boss of node i

void init(int n) // n: Number of nodes
{
    pset = vi(n, 0); // Assign capacity for n nodes
    for(int i = 0; i < n; i++) // For each node i..
        pset[i] = i; // Node i is its own boss
}
int findSet(int i) // Returns the final boss of node i
{
    return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) // Checks if two nodes belong to the same set
{
    return findSet(i) == findSet(j); // Check if nodes have the same boss
}
void unionSet(int i, int j) // Joins the sets of node i and node j
{
    if(!isSameSet(i, j)) // If the nodes belong to different sets..
        pset[findSet(i)] = findSet(j); // Boss of i changes to boss of j
}

int main()
{
    map<tuple<int,int,int>,int> m3d;
    map<pair<int,int>,int> m2d;
    vector<pair<int,int> > r3d;
    set<pair<int,int> > r2d;
    int n,e=0,z=0,a,b,c,u,v,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        if(m3d.find(make_tuple(a,b,c))==m3d.end())
        {
            u=e;
            m3d[make_tuple(a,b,c)]=e++;
        }
        else
            u=m3d[make_tuple(a,b,c)];
        if(m2d.find(make_pair(a,b))==m2d.end())
        {
            x=z;
            m2d[make_pair(a,b)]=z++;
        }
        else
            x=m2d[make_pair(a,b)];
        cin>>a>>b>>c;
        if(m3d.find(make_tuple(a,b,c))==m3d.end())
        {
            v=e;
            m3d[make_tuple(a,b,c)]=e++;
        }
        else
            v=m3d[make_tuple(a,b,c)];
            
        if(m2d.find(make_pair(a,b))==m2d.end())
        {
            y=z;
            m2d[make_pair(a,b)]=z++;
        }
        else
            y=m2d[make_pair(a,b)];
        r3d.push_back(make_pair(u,v));
        if(x!=y)
        	r2d.insert(make_pair(min(x,y),max(x,y)));
    }
    bool close=false;
    init(e);

    for(int i=0;i<r3d.size();i++)
        if(isSameSet(r3d[i].first,r3d[i].second))
        {
            close=true;
            break;
            
        }  
        else
            unionSet(r3d[i].first,r3d[i].second);
    if(close)
        cout<<"True closed chains"<<endl;
    else
         cout<<"No true closed chains"<<endl;
    close=false;
    init(z);
    for(set<pair<int,int> >::iterator i=r2d.begin();i!=r2d.end();i++)
        if(isSameSet((*i).first,(*i).second))
        {
            close=true;
            break;
            
        }  
        else
            unionSet((*i).first,(*i).second);
    if(close)
        cout<<"Floor closed chains"<<endl;
    else
         cout<<"No floor closed chains"<<endl;
    return 0;
}