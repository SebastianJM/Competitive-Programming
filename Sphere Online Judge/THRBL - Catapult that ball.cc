// SEGMENT TREE - RANGE MAXIMUM QUERY 24/04/2016
#include <bits/stdc++.h>

using namespace std;

int t[200005],n;

void build()
{
	for(int i=n-1;i>0;i--)
		t[i]=max(t[i<<1],t[(i<<1)|1]);
}
int query(int l,int r)
{
	int ans=INT_MIN;
	for(l+=n,r+=n;l<=r;l=(l+1)>>1,r=(r-1)>>1)
	{
		if(l&1) ans=max(ans,t[l]);
		if(!(r&1)) ans=max(ans,t[r]);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int q,res=0,u,v;
	cin>>n>>q;
	for(int j=n;j<2*n;j++)
		cin>>t[j];
	build();
	while(q--)
	{
		cin>>u>>v;
		if(u+2<=v)
		{
			if(t[u-1+n]>=query(u,v-2))
				res++;
		}
		else
			res++;
	}
	cout<<res<<"\n";
	return 0;
}