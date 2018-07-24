#include<bits/stdc++.h>
 
using namespace std;

#define INF INT_MAX
#define MAX 201104
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
    int n,q,k,v[MAX];
    pair<int,int> a[MAX];
    char t;
    cin>>n>>q;
    int sq=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
        v[i]=a[i].first;
    }

    for(int i=1;i<=n;i+=sq)
        sort(a+i,a+i+sq);
   
    int ans=0,l,r,bloq_l,bloq_r;
    bool in;
    while(q--)
    {
    	ans=-1;
    	in=false;
		cin>>l>>r>>k;
			
        bloq_l=(l-1)/sq;
        bloq_r=(r-1)/sq;

        if(bloq_l==bloq_r)
        {
            for(int i=l;i<=r;i++)
                if(v[i]!=k)
                {
                	ans=i;
                	break;
                }
        }  
        else
        {
 			
            for(int i=bloq_l+1;i<=bloq_r-1;i++)
            {
           		if(a[i*sq+1].first!=k)
           		{
           			in=true;
           			ans=a[i*sq+1].second;
           			break;
           		}
           		if(a[(i+1)*sq].first!=k)
           		{
           			in=true;
           			ans=a[(i+1)*sq].second;
           			break;
           		}
            }
            if(!in)
	            for(int i=l;i<=sq*(bloq_l+1);i++)
	                if(v[i]!=k)
	                {
	                	ans=i;
	                	in=true;
	                	break;
	                }
	    if(!in)
	            for(int i=bloq_r*sq+1;i<=r;i++)
	                if(v[i]!=k)
	                {
	                	ans=i;
	                	in=true;
	                	break;
	                }
        }
        cout<<ans<<"\n";
    
    }
 
    return 0;
} 