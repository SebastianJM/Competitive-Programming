#include <bits/stdc++.h>
using namespace std;

int p2[32];
map<int,int> m;
int main() 
{
	int n,q,i,e;
	long long ans=0;
	for(i=0;i<32;i++)
		p2[i]=1<<i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>q;
		for(e=0;e<32;e++)
			ans+=m[p2[e]-q];
		m[q]++;
	}
	cout<<ans;
	return 0;
}