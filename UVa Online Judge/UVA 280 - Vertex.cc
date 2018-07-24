#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visit;
int num_visit;

void buscar(int x)
{
		for(int i=0;i<g[x].size();i++)
		{
			if(!visit[g[x][i]])
			{
				num_visit++;
				visit[g[x][i]]=true;
				buscar(g[x][i]);
			}
			
		}
}
int main()
{	
	
	int n,u,v;
	cin>>n;
	while(n)
	{
		g=vector<vector<int> >(n);
		u=1;
		while(u)
		{
			cin>>u;
			if(!u)
				break;
			cin>>v;
			while(v)
			{
				g[u-1].push_back(v-1);
				cin>>v;
			}
		}
		cin>>u;
		for(int i=0;i<u;i++)
		{
			cin>>v;
			num_visit=0;
			visit=vector<bool>(n,false);
			buscar(v-1);
			cout<<n-num_visit;
			for(int e=0;e<n;e++)
				if(!visit[e])
					cout<<" "<<e+1;
			cout<<endl;
		}
		cin>>n;
	}

	return 0;
}