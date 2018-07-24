#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
#define MAX ('z'-'a'+1)
 
 
int main()
{
    fastIO;
    int te,freq[MAX],od,ev,n,it[MAX];
    vi ans;
    string s;
    cin>>te;
    vvi let;
    while(te--)
    {
        cin>>s;
        n=(int)s.length();
        memset(freq,0,sizeof freq);
        let=vvi(MAX);
        for(int i=0;i<n;i++)
        {
            let[s[i]-'a'].pb(i+1);
            freq[s[i]-'a']++;      
        }
        od=0;
        for(int i=0;i<MAX;i++)
                if(freq[i]&1)
                    od++;    
        if(od>=2)
        {
            cout<<-1<<"\n";
            continue;
        }
        ans=vi(n);

        int pos=0;
        for(int i=0;i<MAX;i++)
        {
            if(freq[i]&1)
            {
                od=i;
                continue;
            }

            for(int j=0;j<freq[i];pos++,j+=2)
            {
                ans[pos]=let[i][j];
                ans[n-pos-1]=let[i][j+1];   
            }
        }
        if(n&1)
        {           
            
            for(int j=0;j<freq[od]-1;pos++,j+=2)
            {
                ans[pos]=let[od][j];
                ans[n-pos-1]=let[od][j+1];
            }
            ans[pos]=let[od][let[od].size()-1];
        }

        for(int i=0;i<n;i++)
        {
            if(i>0)
                cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
 
    return 0;
} 