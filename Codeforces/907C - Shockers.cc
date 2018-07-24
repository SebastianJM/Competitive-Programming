#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 200005
#define MOD 1000000007
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<ull,ull> mii;

int main() 
{
    
    fastIO;
    int n=26,con=0,res=0;
    int q,state[n],is[n];
    memset(state,1,sizeof state);
    string a;
    char c,ans;
    ans='.';
    bool found=false;
    cin>>q;
       while(q--)
    {
        cin>>c>>a;
        
        if(c=='!')
        {
            memset(is,0,sizeof is);
            for(int j=0;j<a.size();j++)
                is[a[j]-'a']=1;
            for(int j=0;j<n;j++)
                if(is[j]==0)
                    state[j]=-1;
            for(int j=0;j<a.size();j++)
            {

                {
                    if(state[a[j]-'a']!=-1)
                        state[a[j]-'a']=1;
                }
            }
            
        
            if(found)
                res++;
        }
        else if(c=='.')
        {
            for(int j=0;j<a.size();j++)
            {
                state[a[j]-'a']=-1;
            }
        }
        else
        {
            if(found)
            {
                if(a[0]!=ans)
                res++;
            }
            else
                state[a[0]-'a']=-1;
        }
        if(!found)
        {
            con=0;
            for(int j=0;j<n;j++)
            {

                if(state[j]>=1)
                {
                    con++;
                    ans=('a'+j);
                }
            }
            //cout<<con<<endl;
            if(con==1)
                found=true;
        }
        //cout<<ans<<" "<<res<<endl;
        
    }
    cout<<res<<endl;
    return 0;
}