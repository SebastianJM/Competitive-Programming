#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
 
const int MAX = 100000; 
 
int main()
{
    fastIO;
    int te;
    string a,s;
    cin>>te;
    while(te--)
    {
        cin>>a;
        s="";
        for(int i=0;i<a.size();i++)
            if(isalpha(a[i]))
                s.pb(a[i]);
        bool is=false;
        int ans=0,ar[4];
        
        for(int i=3;i<s.size();i++)
        {
            memset(ar,0,sizeof ar);
            for(int j=i-3;j<=i;j++)
            {
                if(toupper(s[j])=='C')
                    ar[0]++;
                else if(toupper(s[j])=='H')
                    ar[1]++;
                else if(toupper(s[j])=='E')
                    ar[2]++;
                else if(toupper(s[j])=='F')
                    ar[3]++;
            }
            if(ar[0]==1 && ar[1]==1 && ar[2]==1 && ar[3]==1)
            {
                is=true;
                ans++;
            }
        }
        if(is)
            cout<<"lovely "<<ans<<"\n";
        else 
            cout<<"normal\n";
 
    
    }
    return 0;
}  