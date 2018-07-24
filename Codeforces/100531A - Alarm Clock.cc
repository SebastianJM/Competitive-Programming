#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("alarm.in","r",stdin);
    freopen("alarm.out","w",stdout);
    int n,i,j;
    map<int,int> digit;
    cin>>n;
    digit[0]=6;
    digit[1]=2;
    digit[2]=5;
    digit[3]=5;
    digit[4]=5;
    digit[5]=5;
    digit[6]=6;
    digit[7]=3;
    digit[8]=7;
    digit[9]=6;
    bool is=false;
    for(i=0;i<24;i++)
    {
        for(j=0;j<60;j++)
        {
            if(digit[i/10]+digit[i%10]+digit[j/10]+digit[j%10]==n)
            {
                is=true;
                break;
            }
            
        }
        if(is)
            break;
    }
    if(is)
        cout<<(i<10?"0":"")<<i<<":"<<(j<10?"0":"")<<j<<"\n";
    else
        cout<<"Impossible\n";
    return 0;
}