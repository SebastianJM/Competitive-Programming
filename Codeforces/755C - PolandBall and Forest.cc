#include <bits/stdc++.h>

using namespace std;

bool seen[10005];
int dist[10005];

int main() 
{
	int n,ans=0;;
	cin>>n;
	memset(seen,0,sizeof seen);
	for(int i=0;i<n;i++)
	{
		cin>>dist[i];
		dist[i]--;
	}
	for(int i=0;i<n;i++)
		if(!seen[i])
		{
			if(i==dist[dist[i]])
			{
				ans++;
				seen[dist[i]]=true;
				seen[i]=true;
			}
		}
	cout<<ans<<endl;
	return 0;
}