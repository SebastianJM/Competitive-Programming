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
    	int q,l,r;
	cin>>n;
	for(int i=n;i<2*n;i++)
		cin>>t[i];
	cin>>q;
	build();
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		cout<<query(l,r)<<"\n";
	}

	return 0;
}
