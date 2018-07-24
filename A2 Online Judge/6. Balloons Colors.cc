#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t,n,p,u,aux,pp,pu;
    cin>>t;
    while(t--)
    {
        pp=pu=0;
        cin>>n>>p>>u;
        cin>>aux;
        if(p==aux)
            pp=1;
        for(int i=0;i<n-2;i++)
            cin>>aux;
        cin>>aux;
        if(u==aux)
            pu=1;

        if(pu && pp)
            cout<<"BOTH"<<endl;
        else if(pu)
            cout<<"HARD"<<endl;
        else if(pp)
            cout<<"EASY"<<endl;
        else
            cout<<"OKAY"<<endl;
    }
    return 0;
}