#include<bits/stdc++.h>
 
using namespace std;

#define MAX 110004
#define SQRTT 500
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q,k,a[SQRTT],v[MAX],t;
	map<int,int> mp[SQRTT];
	map<int,int>::iterator it;
	cin>>n>>q;
	int sq=sqrt(n);
	a[0]=v[0]=0;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	
	for(int i=1,e=0;i<=n;)
	{
		a[e]=0;
		for(int j=0;j<sq;j++,i++)
			if(i<=n)
			{
				a[e]^=v[i];
				mp[e][a[e]]++;
			}
		
		e++;
	}
	
	int ans=0,con,r,bloq_l,bloq_r,prev,block;
	while(q--)
	{
		cin>>t;
		ans=0;
		if(t==2)
		{
			cin>>r>>k;
			bloq_l=0;
			bloq_r=(r-1)/sq;
			con=0;
			if(bloq_l==bloq_r)
				for(int i=1;i<=r;i++)
				{
					con^=v[i];
					if(con==k)
						ans++;
				}
			
			else
			{
				prev=0;
				for(int i=bloq_l;i<bloq_r;i++)
				{
					it=mp[i].find(prev^k);
					if(it!=mp[i].end())
						ans+=(*it).second;
					prev^=a[i];
				}
				for(int i=bloq_r*sq+1;i<=r;i++)
				{
					prev^=v[i];
					if(prev==k)
						ans++;	
				}
			}
			cout<<ans<<"\n";
		}
		else
		{
			cin>>r>>k;
			block=(r-1)/sq;
			mp[block].clear();
			v[r]=k;
			a[block]=0;
			for(int i=block*sq+1;i<=min(n,(block+1)*sq);i++)
			{
				a[block]^=v[i];
				mp[block][a[block]]++;
			}
		}
	
	} 
	return 0;
} 
