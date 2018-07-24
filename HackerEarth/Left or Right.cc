#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 200005
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    fastIO;
    
    int n,q,a,b;
    char c;
    vector<int> freq[MAX];
    
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        freq[a].push_back(i);
    }
    for(int i=0;i<q;i++)
    {
        cin>>a>>b>>c;
        if(freq[b].size()==0)
        {
            cout<<"-1\n";
            continue;
        }
        
        vector<int>::iterator it=lower_bound(freq[b].begin(),freq[b].end(),a);
        
        int ind=it-freq[b].begin();

        if(freq[b][ind]==a)
        {
            cout<<0<<"\n";
            continue;
        }
        if(c=='L')
        {   
            
            int sz=freq[b].size();
            if(ind>=sz)
                ind--;
            if(freq[b][ind]>a)
                ind=freq[b][(ind-1+sz)%sz];
            else
                ind=freq[b][ind];
            if(a>ind)
                cout<<a-ind<<"\n";
            else
                cout<<a+n-ind<<"\n";
            
        }
        else
        {
            int sz=freq[b].size();
            if(ind>=sz)
                ind=0;
            ind=freq[b][ind];
            if(a>ind)
                cout<<n-a+ind<<"\n";
            else
                cout<<ind-a<<"\n";
        }
    }
    return 0;
}
