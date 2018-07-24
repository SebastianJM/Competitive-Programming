#include <bits/stdc++.h>
using namespace std;
#define MAX 2503
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	pair<vector<int>::iterator,vector<int>::iterator> z;
	int a[MAX],b[MAX],c[MAX],d[MAX];
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	
	for(int i=0;i<n;i++)
		for(int e=0;e<n;e++)
			v.push_back(c[i]+d[e]);
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
		for(int e=0;e<n;e++)
		{
			z=equal_range(v.begin(),v.end(),-(a[i]+b[e]));
			ans+=(z.second-z.first);	
		}
		
	cout<<ans<<"\n";
	return 0;
} 