#include <bits/stdc++.h>

using namespace std;

char matriz[52][52],temp,aux;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
int con,f,c;
vector<vector<int>> g;
vector<pair<bool,int> > visitados;

inline void bfs(int x,int y)
{
	con++;
	temp=matriz[x][y];
	matriz[x][y]='.';
	for(int i=0;i<4;i++)
		if(x+xx[i]<f && x+xx[i]>=0 && y+yy[i]<c && y+yy>=0 && matriz[x+xx[i]][y+yy[i]]==temp)
			bfs(x+xx[i],y+yy[i]);
}
bool funcion(pair<int,char> a,pair<int,char> b)
{
	if(a.first>b.first)
		return false;
	else if(a.first==b.first)
	{
		if(a.second>b.second)
			return true;
		else
			return false;
	}
	else
		return true;

}
int main()
{
	int t=1;
	while(1)
	{
		cin>>f>>c;
		if(!f && !c)
			return 0;
		memset(matriz,0,sizeof matriz);
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
				cin>>matriz[i][e];
		vector<pair<int,char>> res;
		for(int i=0;i<f;i++)
		{
			for(int e=0;e<c;e++)
			{
				if(matriz[i][e]!='.')
				{
					con=0;
					aux=matriz[i][e];
					bfs(i,e);
					res.push_back(pair<int,char>(con,aux));
				}
			}
		}

		sort(res.rbegin(),res.rend(),funcion);
		cout<<"Problem "<<t++<<":"<<endl;
		for(int i=0;i<res.size();i++)
			cout<<res[i].second<<" "<<res[i].first<<endl;
	}

	return 0;
}
