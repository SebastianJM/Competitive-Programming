/*
1) sort menor -> mayor
2) máx distancia entre contiguos: v[3],v[1],v[0],v[2],v[4]...
3) sort mayor -> menor
4) 2)
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t,n,i,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v(n);
		for(i=0;i<n;i++)
			cin>>v[i];
		ans=INT_MIN;
		sort(v.begin(),v.end());
		for(i=2;i<n;i++)
				ans=max(ans,v[i]-v[i-2]);
		ans=max(ans,v[1]-v[0]);
		sort(v.rbegin(),v.rend());
		for(i=2;i<n;i++)
				ans=max(ans,v[i-2]-v[i]);
		ans=max(ans,v[0]-v[1]);
		cout<<ans<<"\n";
	}
	return 0;
}
