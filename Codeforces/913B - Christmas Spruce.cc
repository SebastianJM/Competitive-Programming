#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1005

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi g;
int n,a,ans[MAX];
int dfs(int x)
{
	if(g[x].size()==0)
		return 1;
	//cout<<"IN "<<x<<" "<<ans[x]<<endl;
	for(int i=0;i<g[x].size();i++)
	{
		ans[x]+=dfs(g[x][i]);
	}
	return 0;
}

int main() 
{
	fastIO;
	cin>>n;
	g=vvi(n+2);
	for(int i=2;i<=n;i++)
	{
		cin>>a;
		g[a].push_back(i);
	}
	memset(ans,0,sizeof ans);
	bool is=true;
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" "<<ans[i]<<endl;
		if(g[i].size()>0 && ans[i]<3)
		{
			is=false;
			break;
		}
			
	}
	if(is)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}