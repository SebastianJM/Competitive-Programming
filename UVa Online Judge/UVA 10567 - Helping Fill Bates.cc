#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,q;
    int n,len='z'-'a'+1;
    vector<vector<int> > v(len);
    vector<int>::iterator it;
    cin>>s;
    for(int i=0;i<s.size();i++)
        v[s[i]-'a'].push_back(i);
    cin>>n;
    while(n--)
    {
        cin>>q;
        int index=0,mini=1000000,maxi=-1;
        bool ans=true;
        for(int i=0;i<q.size();i++)
        {
            it=lower_bound(v[q[i]-'a'].begin(),v[q[i]-'a'].end(),index);
           
            if(it!=v[q[i]-'a'].end())
            {
                mini=min(mini,*it);
                maxi=max(maxi,*it);
                index=*it+1;
            }
            else
            {
                ans=false;
                break;
            }
        }
        if(ans)
            cout<<"Matched "<<mini<<" "<<maxi<<"\n";
        else
            cout<<"Not matched\n";
       
    }
    return 0;
}