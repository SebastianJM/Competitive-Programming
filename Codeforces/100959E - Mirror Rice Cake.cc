#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	long long v[1004];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	long long ans=1,suma=v[0];
	for(int i=1;i<n;i++)
	{
		if(v[i]>suma)
		{
			suma+=v[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}