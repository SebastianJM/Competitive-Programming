#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,k;
	cin>>k>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	int ans=(1<<20);
	k--;
	for(int i=k;i<n;i++)
		ans=min(ans,v[i]-v[i-k]);
	cout<<ans<<endl;
	return 0;
}