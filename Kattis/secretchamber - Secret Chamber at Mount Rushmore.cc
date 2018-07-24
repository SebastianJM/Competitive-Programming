#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

bool M[MAX][MAX];
int n; 

void init() 
{ 
    memset(M, false, sizeof M); 
    for(int i=0;i<n;i++)
        M[i][i]=true;
}

void floyd()
{
    for(int k = 0; k < n ; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                M[i][j] = M[i][j] | (M[i][k] & M[k][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,q;
    char a,b;
    bool is;
    string x,y;
    n=MAX;
    cin>>t>>q;
    init();
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        M[a-'a'][b-'a']=true;
    }
    floyd();
    while(q--)
    {
        cin>>x>>y;
        if(x.size()!=y.size())
        {
            cout<<"no\n";
            continue;
        }
        is=true;
        
        for(int i=0;i<x.size();i++)
            if(!M[x[i]-'a'][y[i]-'a'])
            {
                is=false;
                break;
            }
        if(is)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}