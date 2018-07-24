#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,ans;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ans=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='<')
                s[i]='>';
            else if(s[i]=='>')
                s[i]='<';
        for(int i=1;i<s.size();i++)
            if(s[i]=='<' && s[i-1]=='>')
                ans++;
        cout<<ans<<endl;
    }
    return 0;
} 