#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

#define pb(x) push_back(x) 
#define MAX 100005
#define VAL 2000005
#define EPS 1e-7

int main()
{
  int t,k,x,y,a,b,le[VAL],sumP[VAL],sumI[VAL];
  bool p_a[VAL],p_b[VAL];
  ll n,ac;
  cin>>t;
  while(t--)
  {
    ac=0;
    cin>>n>>k;
    memset(sumI,0,sizeof sumI);
    memset(sumP,0,sizeof sumP);
    memset(p_a,0,sizeof p_a);
    memset(p_b,0,sizeof p_b);
    for(int i=0;i<k;i++)
    {
      cin>>x>>y;
      a=x+y-1;  
      b=x-y+n;
      le[i]=a;
      if(!p_a[a])
      	ac+=(a>n?2*n-a:a);
      if(!p_b[b])
      	ac+=(b>n?2*n-b:b);
      p_a[a]=true;
      p_b[b]=true;
      if(b&1)
        sumI[b]=1;
      else
        sumP[b]=1;
    }
    for(int i=1;i<VAL;i++)
    {
      sumI[i]+=sumI[i-1];
      sumP[i]+=sumP[i-1];
    }
    memset(p_a,0,sizeof p_a);
    for(int i=0;i<k;i++)
    {
    	if(!p_a[le[i]])
    	{
	    	if(n&1)
	    	{
		      	if(le[i]<=n)
			  		ac-=(le[i]&1?sumI[n+le[i]-1]-sumI[n-le[i]]:sumP[n+le[i]-1]-sumP[n-le[i]]);
		      	else
		        	ac-=(le[i]&1?sumI[n+(2*n-le[i])-1]-sumI[n-(2*n-le[i])]:sumP[n+(2*n-le[i])-1]-sumP[n-(2*n-le[i])]);
	    	}
	    	else
	    	{
	    		if(le[i]<=n)
			  		ac-=(le[i]&1?sumP[n+le[i]-1]-sumP[n-le[i]]:sumI[n+le[i]-1]-sumI[n-le[i]]);
		      	else
		        	ac-=(le[i]&1?sumP[n+(2*n-le[i])-1]-sumP[n-(2*n-le[i])]:sumI[n+(2*n-le[i])-1]-sumI[n-(2*n-le[i])]);
	    	}
    	}
    	p_a[le[i]]=true;
    }
    cout<<n*n-ac<<"\n";
  }
}
