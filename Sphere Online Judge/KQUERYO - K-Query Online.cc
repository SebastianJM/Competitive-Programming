#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;
 
#define pb(x) push_back(x) 
#define MAX 200004
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int n,q,k,a[MAX],v[MAX];
    memset(a,0,sizeof a);
    cin>>n;
    int sq=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[i]=a[i];
    }
        
    for(int i=1;i<=n;i+=sq)
        sort(a+i,a+i+sq);
 
    cin>>q;
    
    int last_ans=0,l,r,bloq_l,bloq_r;
    while(q--)
    {
        cin>>l>>r>>k;
        l^=last_ans;
        r^=last_ans;
        k^=last_ans;
        last_ans=0;
 
        if(r>=l)
        {
        	if(!l && !r)
        	{
        		cout<<"0\n";
        		continue;
        	}
	        bloq_l=(l-1)/sq;
	        bloq_r=(r-1)/sq;
	        if(bloq_l==bloq_r)
	            for(int i=l;i<=r;i++)
	                last_ans+=(v[i]>k?1:0);
	        else
	        {
	            for(int i=l;i<=sq*(bloq_l+1);i++)
	                last_ans+=(v[i]>k?1:0);
	            for(int i=bloq_r*sq+1;i<=r;i++)
	                last_ans+=(v[i]>k?1:0);
	            for(int i=bloq_l+1;i<=bloq_r-1;i++)
	                last_ans+=(i+1)*sq+1-(int)(upper_bound(a+i*sq+1,a+(i+1)*sq+1,k)-a) ;
	        }
        }
        cout<<last_ans<<"\n";
    }
 
    return 0;
}  