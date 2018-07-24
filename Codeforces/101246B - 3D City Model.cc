#include <bits/stdc++.h>
using namespace std;

int main()
{
    read("input.txt");
    rite("output.txt");
    
    int m[103][103],f,c;
    string s;
    cin>>f>>c;
    int ans=0;
    for(int i=0;i<f;i++)
    {
        cin>>s;
        for(int e=0;e<c;e++)
            m[i][e]=s[e]-'0';
    }

    for(int i=0;i<f;i++)
        for(int e=0;e<c;e++)
        {
            if(m[i][e]>0)
                ans+=2;
        }
    for(int i=0;i<f;i++)
        ans+=m[i][0]+m[i][c-1];
    for(int i=0;i<c;i++)
        ans+=m[0][i]+m[f-1][i];       
    for(int i=0;i<f;i++)
    {
        for(int e=1;e<c;e++)  
            if(m[i][e]>m[i][e-1])
                ans+=m[i][e]-m[i][e-1];
        for(int e=0;e<c-1;e++)  
            if(m[i][e]>m[i][e+1])
                ans+=m[i][e]-m[i][e+1];            
    }    
    for(int i=0;i<c;i++)
    {
        for(int e=1;e<f;e++)  
            if(m[e][i]>m[e-1][i])
                ans+=m[e][i]-m[e-1][i];
        for(int e=0;e<f-1;e++)  
            if(m[e][i]>m[e+1][i])
                ans+=m[e][i]-m[e+1][i];           
    }    
    cout<<ans<<endl;
    return 0;
}