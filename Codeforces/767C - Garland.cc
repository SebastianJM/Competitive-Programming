#include <bits/stdc++.h>
using namespace std;

#define MAX 1000003
vector<vector<int> > g;
int w[MAX],obj;
vector<int> ans;
int dfs(int x)
{
	int cnt=0;
	for(int i=0;i<g[x].size();i++)
		cnt+=dfs(g[x][i]);
	cnt+=w[x];
	if(cnt==obj)
	{
		ans.push_back(x);
		return 0;
	}
	return cnt;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,a,cnt=0,f;
	cin>>n;
	g=vector<vector<int> >(n+2);
	for(int i=1;i<=n;i++)
	{
		cin>>a>>w[i];
		if(a==0)
			f=i;
		cnt+=w[i];
		g[a].push_back(i);
	}
	if(cnt%3!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	obj=cnt/3;

	dfs(f);
	if(ans.size()<2 || ans[0]==f || ans[1]==f)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
		cout<<min(ans[0],ans[1])<<" "<<max(ans[0],ans[1])<<endl;
	return 0;
}