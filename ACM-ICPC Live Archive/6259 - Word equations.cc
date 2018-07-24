#include <bits/stdc++.h>
 
using namespace std;
 
map<string,int> id_match;
vector<vector<int> > equations;
string values[2000];
bool visited[2000];
int dp[2000][2002];
int c;
string des;

int matching(string s)
{
	map<string,int>::iterator it=id_match.find(s);
	if(it!=id_match.end())
		return it->second;
	id_match[s]=c;
	visited[c]=false;
	c++;
	return c-1;
}

void dfs(int s)
{
	visited[s]=true;
	if(equations[s].size()==0)
	{
		for(int i=0;i<des.size();i++)
		{
			int j=i;
			for(int e=0;e<values[s].size();e++)
				if(j<des.size() && values[s][e]==des[j])
					j++;
			dp[s][i]=j;
		}
		return;
	}
	if(!visited[equations[s][0]])
		dfs(equations[s][0]);
	if(!visited[equations[s][1]])
		dfs(equations[s][1]);
	for(int i=0;i<des.size();i++)
	{
		int j=dp[equations[s][0]][i];
		if(j<des.size())
			j=dp[equations[s][1]][j];
		dp[s][i]=j;
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,left_id,right1_id,right2_id;
	string a,left,equal,right1,plus,right2,ori;
	bool trade;
	cin>>t;
 
	while(t--)
	{
		id_match.clear();
		equations=vector<vector<int> >(2000);
		c=0;
		cin>>n;
		trade=false;
		for(int k=0;k<n;k++)
		{
			if(!trade)
				cin>>left;
			cin>>equal>>right1;
			cin>>plus;
			if(plus[0]=='+')
			{
				cin>>right2;
				left_id=matching(left);
				right1_id=matching(right1);
				right2_id=matching(right2);
				equations[left_id].push_back(right1_id);
				equations[left_id].push_back(right2_id);
				trade=false;
			}
			else
			{
				left_id=matching(left);
				values[left_id]=right1;
				if(k==n-1)
					ori=plus;
				else
					left=plus;
				trade=true;
			}
		}
		if(!trade)
			cin>>ori;
		cin>>des;

		dfs(id_match[ori]);
		if(dp[id_match[ori]][0]==des.size())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}