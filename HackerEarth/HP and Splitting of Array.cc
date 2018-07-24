#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
#define MAX 100005
 
 
ll t[MAX*2]; // Segment Tree (Root is t[1])
int n; // Number of elements of the array
void build() // Builds the segment tree
{
 for(int i = n - 1; i > 0; i--) // For each non-leaf node..
 t[i] = t[i << 1] + t[i << 1 | 1]; // Update according to both children
}
void update(int i, ll val) // Sets array[i] to val (i in range [0, N-1])
{
 for(t[i += n] = val; i >>= 1; ) // Update leaf node, then go up..
 t[i] = t[i << 1] + t[i << 1 | 1]; // Update according to children
}
ll query(int l, int r) // Range Sum Query in range [l,r]
{
 ll ans = 0;
 for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
 {
 if( l & 1 ) ans = ans + t[l]; // For left pointer, odd nodes matter
 if(!(r & 1)) ans = t[r] + ans; // For right pointer, even nodes matter
 }
 return ans;
}
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int te,can;
	vi a,v;
	cin>>te;
	while(te--)
	{
	    cin>>can;
	    n=can+1;
		  a=v=vi(can);
	    for(int i=0;i<can;i++)
	    {
	        cin>>a[i];
	        v[i]=a[i];
	    }
	    memset(t,0,sizeof t);
	    map<int,int> mp;    
	    sort(a.begin(),a.end());
	    for(int i=0,c=1;i<can;i++)
	        if(mp.find(a[i])==mp.end())
                mp[a[i]]=c++;
	    for(int i=0;i<can;i++)
	        v[i]=mp[v[i]];
	        
      ll acum=0,aux;
	    for(int i=0;i<can;i++)
	    {
	        update(v[i],1LL);
          acum+=query(v[i]+1,can);
          
	    }
	    ll fi=acum;
	    for(int i=0;i<can-1;i++)
	    {
	      aux=query(0,v[i]-1);
	      
	      acum-=aux;
	      acum+=(can-1-aux);
	      if(i!=0)
	        cout<<" ";
	      cout<<acum;
	    }
	    if(can>1)
	      cout<<" ";
	    cout<<fi<<"\n";
 
	}
	return 0;
}