#include <bits/stdc++.h>
using namespace std;

#define MAX 200005
#define INF (INT_MAX-MAX-1)
int main() 
{
	int n,v[MAX],ans[MAX];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		ans[i]=INT_MAX;
	}
	int it=INF;
	for(int i=0;i<n;i++)
	{
		if(v[i]==0)
			it=0;
		ans[i]=it++;
	}
	it=INF;
	for(int i=n-1;i>=0;i--)
	{
		if(v[i]==0)
			it=0;
		ans[i]=min(ans[i],it);
		it++;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0)
			cout<<" ";
		cout<<ans[i];
	}
		
	return 0;
}