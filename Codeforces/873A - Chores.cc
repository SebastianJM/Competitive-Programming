#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 102
int main() 
{
    fastIO;
    int n,k,x,a,ans;
    ans=0;
    cin>>n>>k>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(i<n-k)
            ans+=a;
    }
    ans+=k*x;
    cout<<ans<<endl;
    return 0;
}