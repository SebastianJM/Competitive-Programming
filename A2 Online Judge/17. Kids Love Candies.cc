#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t,n,k,aux,total;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        total=0;
        for(int i=0;i<n;i++)
        {
            cin>>aux;
            aux-=aux%k;
            total+=aux/k;
        }
        cout<<total<<endl;
    }
        return 0;
}