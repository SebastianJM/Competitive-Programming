#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main()
{
    int p,x,y;
    
    int i=0,s;
    cin>>p>>x>>y;
    int xx=x;
    while(xx>=y)
    {
        s=((xx)/50)%475;
            for(int j=0;j<25;j++)
            {
                s=(s*96+42)%475;
                if(26+s==p)
                {
                    cout<<0<<endl;
                    return 0;
                }
            }
        xx-=50;
    }
    while(1)
    {
        if(x+100*i>=y)
        {
            s=((x+100*i)/50)%475;
            for(int j=0;j<25;j++)
            {
                s=(s*96+42)%475;
                if(26+s==p)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
            if(x+100*i-50>=y)
            {
                s=((x+100*i-50)/50)%475;
                for(int j=0;j<25;j++)
                {
                    s=(s*96+42)%475;
                    if(26+s==p)
                    {
                        cout<<i<<endl;
                        return 0;
                    }
                }
            }
        }
        
        i++;
    }
    
    return 0;
}