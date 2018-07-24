#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q,l,r,v[MAX],inc_dist[MAX],dec_dist[MAX];
	cin>>n>>q;
	memset(inc_dist,0,sizeof inc_dist);
	memset(dec_dist,0,sizeof dec_dist);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=n-2;i>=0;i--)
		if(v[i]<=v[i+1])
			inc_dist[i]=inc_dist[i+1]+1;
	for(int i=n-2;i>=0;i--)
		if(v[i]>=v[i+1])
			dec_dist[i]=dec_dist[i+1]+1;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		l--;r--;
		if(l+inc_dist[l]+dec_dist[l+inc_dist[l]]>=r)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}