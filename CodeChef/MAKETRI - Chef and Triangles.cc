#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define MAX LLONG_MAX-1
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll ans=0,n,l,r,v[1000005];
	pair<ll,ll> seg[1000004];
	cin>>n>>l>>r;
	for(ll i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	for(ll i=0;i<n-1;i++)
		seg[i]=make_pair(max(l,v[i+1]-v[i]+1),min(r,v[i+1]+v[i]-1));
	ll fin=MAX,lo,hi;
	for(ll i=n-2;i>=0;i--)
	{
		ans+=max(seg[i].second-seg[i].first+1,0LL);
		lo=max(fin,seg[i].first);
		hi=seg[i].second;
		ans-=max(hi-lo+1,0LL);
		fin=min(seg[i].first,fin);
	}
	cout<<ans<<endl;
	return 0;
}  