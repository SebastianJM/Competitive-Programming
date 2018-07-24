#include <bits/stdc++.h>

using namespace std;

int precio[25][25];
bool dp[250][25];
int t,n,g,c;

void fill(int sobrante,int i_id,int sub_id)
{
    sobrante-=precio[i_id][sub_id];
    //cout<<"i_id: "<<i_id<<" sub_id: "<<sub_id<<" Precio: "<<precio[i_id][sub_id]<< " Sobrante: "<<sobrante<<endl;
    if(dp[sobrante][i_id])
            return;
    if(sobrante>=0)
        dp[sobrante][i_id]=true;
    else
        return;
    if(g>i_id+1)
        for(int i=1;i<=precio[i_id+1][0];i++)
            fill(sobrante,i_id+1,i);
}

int main() 
{
    cin>>t;
    while(t--)
    {
        cin>>n>>g;
        memset(dp,false,sizeof dp);
        for(int i=0;i<g;i++)
        {
            cin>>precio[i][0];
            for(int e=1;e<=precio[i][0];e++)
                cin>>precio[i][e];
        }
        for(int i=1;i<=precio[0][0];i++)
            fill(n,0,i);
        int z;
        for(z=0;z<=n && !dp[z][g-1];z++);
        
        if(z==n+1)
            cout<<"no solution"<<endl;
        else
            cout<<n-z<<endl;
    }
    return 0;
}