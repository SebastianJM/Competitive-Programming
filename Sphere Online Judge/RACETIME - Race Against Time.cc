#include<bits/stdc++.h>
 
using namespace std;

#define INF INT_MAX
#define MAX 101004
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int n,q,k,a[MAX],v[MAX];
    char t;
    cin>>n>>q;
    int sq=sqrt(n);
    a[0]=v[0]=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[i]=a[i];
    }
    for(int i=n+1;i<MAX;i++)
    	a[i]=v[i]=INF;
    for(int i=1;i<=n;i+=sq)
        sort(a+i,a+i+sq);
        
    int ans=0,l,r,bloq_l,bloq_r;
    while(q--)
    {
    	cin>>t;
    	ans=0;
    	if(t=='C')
    	{
    		cin>>l>>r>>k;
				
	        bloq_l=(l-1)/sq;
	        bloq_r=(r-1)/sq;
	
	        if(bloq_l==bloq_r)
	            for(int i=l;i<=r;i++)
	                ans+=(v[i]<=k?1:0);
	        else
	        {
	            for(int i=l;i<=sq*(bloq_l+1);i++)
	                ans+=(v[i]<=k?1:0);
	            for(int i=bloq_r*sq+1;i<=r;i++)
	                ans+=(v[i]<=k?1:0);
	            for(int i=bloq_l+1;i<=bloq_r-1;i++)
	                ans+=(int)(upper_bound(a+i*sq+1,a+(i+1)*sq+1,k)-a)-(i*sq+1) ;
	        }
	        cout<<ans<<"\n";
    	}
        else
        {
        	cin>>l>>k;
        	bloq_l=(l-1)/sq;
        	a[(int)(lower_bound(a+bloq_l*sq+1,a+(bloq_l+1)*sq+1,v[l])-a)]=k;
        	v[l]=k;
        	sort(a+bloq_l*sq+1,a+(bloq_l+1)*sq+1);
        }
        
    }
 
    return 0;
} 