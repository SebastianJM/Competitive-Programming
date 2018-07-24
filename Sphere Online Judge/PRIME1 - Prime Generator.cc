#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 100100

bool visit[MAX];

void segmented_sieve(int a,int b)
{
    Vi primes;
    int sq=sqrt(b),q;
    memset(visit,0,sizeof visit);
    for(int i=2;i<=sq;i++)
        if(!visit[i])
        {
            visit[i]=true;
            primes.pb(i);
            for(int e=2*i;e<=sq;e+=i)
                visit[e]=true;
        }
    memset(visit,0,sizeof visit);
    for(int i=0;i<primes.size();i++)
    {
        q=ceil(a/primes[i])*primes[i];
        for(int e=q;e<=b;e+=primes[i])
        {
            if(e<a || e==primes[i])
                continue;
            visit[e-a]=true;
        }
            
    }
    for(int i=0;i<b-a+1;i++)
        if(!visit[i])
            cout<<i+a<<"\n";
}
int main()
{
    int t,a,b;
    bool f=true;
    cin>>t;
    while(t--)
    {
    	if(!f)
    		cout<<"\n";
    	f=false;
        cin>>a>>b;
        if(a==1)
            a=2;
        
        segmented_sieve(a,b);
    }
    return 0;
}