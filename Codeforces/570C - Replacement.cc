#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
char s[300005];
int main()
{
    char t;
    int n,q,total(0),a;
    cin>>n>>q;
    cin>>s[1];
    for(int i=2;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]=='.'&&s[i-1]=='.')
            total++;
    }
    for(int i=0;i<q;i++)
    {
        cin>>a>>t;
        if(s[a+1]=='.'&&s[a]=='.')
            total--;
        if(s[a-1]=='.'&&s[a]=='.')
            total--;
        s[a]=t;
        if(s[a+1]=='.'&&s[a]=='.')
            total++;
        if(s[a-1]=='.'&&s[a]=='.')
            total++;
        cout<<total<<endl;
    }

    return 0;
}