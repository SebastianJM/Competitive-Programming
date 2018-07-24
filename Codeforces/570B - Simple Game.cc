#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(m-1>0)
    {
        if(m>n-m)
            cout<<m-1;
        else 
            cout<<m+1;
    }
    else if(m+1<=n)
        cout<<m+1;
    else
        cout<<m;
    return 0;
}