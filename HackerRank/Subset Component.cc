#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long v[30];
bool visit[30];
int mask;
void dfs(int index)
{
	visit[index]=true;
	for(int i=0;i<n;i++)
	{
		if(mask&(1<<i) && !visit[i] && (v[index]&v[i]))
		{
			visit[i]=true;
			dfs(i);
		}
	}
}
int findSets()
{
	memset(visit,0,sizeof visit);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(mask&(1<<i) && v[i] && !visit[i])
		{
			visit[i]=true;
			dfs(i);
			ans++;
		}
	}
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		if(__builtin_popcountll(v[i])==1)
			v[i]=0;
	}

	int a;
	unsigned long long b;
	for(int i=0;i<(1<<n);i++)
	{
		mask=i;
		b=0;
		for(int i=0;i<n;i++)
		{
			if(mask&(1<<i))
				b|=v[i];
		}
		a=findSets();
		ans+=64-(__builtin_popcountll(b))+a;
	}
	cout<<ans<<endl;
	return 0;
}