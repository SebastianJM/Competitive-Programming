#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,a;
    vi grupos;
    cin>>t;
    while(t--)
    {
        cin>>n;
        grupos.clear();
        cin>>a;
        grupos.push_back(a);
        for(int i=1;i<n;i++)
        {
            cin>>a;
            if(a<grupos[grupos.size()-1])
                grupos.push_back(a);
            else
            {
                int pos=upper_bound(grupos.begin(),grupos.end(),a,comp)-grupos.begin();
                grupos[pos]=a;
            }
        }
        cout<<grupos.size()<<"\n";
    }
    return 0;
} 