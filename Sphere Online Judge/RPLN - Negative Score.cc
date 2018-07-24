// SEGMENT TREE - RANGE MINIMUM QUERY 23/04/2016
#include <bits/stdc++.h>

using namespace std;

int t[200005],n;

void build()
{
	for(int i=n-1;i>0;i--)
		t[i]=min(t[i<<1],t[(i<<1)|1]);
}
int query(int l,int r)
{
	int ans=INT_MAX;
	for(l+=n,r+=n;l<=r;l=(l+1)>>1,r=(r-1)>>1)
	{
		if(l&1) ans=min(ans,t[l]);
		if(!(r&1)) ans=min(ans,t[r]);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int h,q,u,v;
	cin>>h;
	for(int i=1;i<=h;i++)
	{
		
		cin>>n>>q;
		for(int j=n;j<2*n;j++)
			cin>>t[j];
		build();
		cout<<"Scenario #"<<i<<":\n";
		while(q--)
		{
			cin>>u>>v;
			cout<<query(u-1,v-1)<<"\n";
		}
	}
	return 0;
}
