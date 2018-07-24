#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int n;
vvi g;
vi match;
vb visit;

char tab[101][101];
int fake_col[101][101];
int fake_fil[101][101];
int augmenting(int v)
{
	if(visit[v])
		return 0;
	visit[v]=true;
	for(int i=0;i<(int)g[v].size();i++)
	{
		int u=g[v][i];
		if(match[u]==-1||augmenting(match[u]))
		{
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

int MCBM(int left)
{
	int ans=0;
	match=vi(n,-1);
	for(int i=0;i<left;i++)
	{
		visit=vb(left,false);
		ans+=augmenting(i);
	}
	return ans;
}

int main() 
{
	
	while(cin>>n)
	{
		bool goes;
		int left=n*n,right=n*n,it;
		
		g=vvi(left+right);
		memset(fake_fil,-1,sizeof fake_fil);
		memset(fake_col,-1,sizeof fake_col);
		it=0;
		goes=false;
		for(int i=0;i<n;i++)
		{
			for(int e=0;e<n;e++)
			{
				cin>>tab[i][e];
				
				if(tab[i][e]=='.')
				{
					fake_fil[i][e]=it;
					goes=true;
				}
				else if(goes)
				{
					goes=false;
					it++;
				}
				else
					goes=false;
				
			}
			goes=false;
			it++;
		}
		it=0;
		goes=false;
		
		for(int e=0;e<n;e++)
		{
			for(int i=0;i<n;i++)
			{
				
				if(tab[i][e]=='.')
				{
					fake_col[i][e]=it;
					goes=true;
				}
				else if(goes)
				{
					goes=false;
					it++;
				}
				else
					goes=false;
				
			}
			goes=false;
			it++;
		}
		for(int i=0;i<n;i++)
			for(int e=0;e<n;e++)
			{
				if(fake_fil[i][e]>=0 && fake_col[i][e]>=0)
				{
					g[fake_fil[i][e]].push_back(fake_col[i][e]+left);
					g[fake_col[i][e]+left].push_back(fake_fil[i][e]);
				}
			}
		
		n=left+right;
		cout<<MCBM(left)<<endl;
		
	}
	return 0;
}