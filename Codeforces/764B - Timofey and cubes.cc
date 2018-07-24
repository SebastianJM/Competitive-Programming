#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int n,v[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1,e=n-i+1;i<e;i+=2,e-=2)
	{
		v[i]+=v[e];
		v[e]=v[i]-v[e];
		v[i]-=v[e];
	}
	bool first=true;
	for(int i=1;i<=n;i++)
	{
		if(!first)
			cout<<" ";
		first=false;
		cout<<v[i];
	}
	
	return 0;
}