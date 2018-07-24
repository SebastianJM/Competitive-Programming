#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x)
#define PI  (2.0*acos(0.0))
#define MAX 100005
#define MOD 1000003
#define EPS 1e-7
 
int main() 
{
    fastIO;
    int t,n,ar[MAX],br[MAX],v[MAX];
    ull ans[MAX];
    ull s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>v[i];
        memset(ar,0,sizeof ar);
        memset(br,0,sizeof br);
        memset(ans,0,sizeof ans);
        for(int i=0;i<n;i++)
        {
            s=0;
            ar[i]++;
            for(int j=i+1;j<n;j++)
            {
                if(s>v[i])
                {
                    ar[j-1]--;
                    break;
                }
                s+=v[j];
                
                
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            s=0;
            br[i]++;
            for(int j=i-1;j>=0;j--)
            {
                if(s>v[i])
                {
                    br[j+1]--;
                    break;
                }
                s+=v[j];
                
                
            }
        }
        int it=0;
        for(int i=0;i<n;i++)
        {
            //cout<<ar[i]<<" ";
            ans[i]+=it;
            it+=ar[i];  
        }

        it=0;
        for(int i=n-1;i>=0;i--)
        {
            
            ans[i]+=it;
            it+=br[i];          
        }
       
        for(int i=0;i<n;i++)
        {
            if(i)
                cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
 