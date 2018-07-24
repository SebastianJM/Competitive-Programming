#include <bits/stdc++.h>
using namespace std;

int m[100001];
vector<int> cost;
int main() 
{
	int n,a,q;
	cin>>n;
	cost=vector<int>(n);
	for(int i=0;i<n;i++)
		cin>>cost[i];
	sort(cost.begin(),cost.end());
	for(int i=0,e=0;i<cost[n-1];i++)
	{
		if(i>=cost[e])
		{
			e++;
			i--;
			continue;
		}
		m[i]=e;
	}
	for(int i=cost[n-1];i<100001;i++)
		m[i]=n;
		
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a;
		if(a>=100000)
			cout<<m[100000]<<endl;
		else
			cout<<m[a]<<endl;
	}
	return 0;
}