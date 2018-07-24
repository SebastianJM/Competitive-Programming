#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,float>> > g;
vector<vector<int> > bloqueo;
vector<bool> visita;
vector<pair<int, int> > puntos;
int n,r;
bool comp;
float distancia(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void dfs(int x)
{
	if(x==r+1)
		comp=true;
	visita[x]=true;
	if(!comp)
	{
		for(int i=0;i<(int)bloqueo[x].size();i++)
			if(bloqueo[x][i] && !visita[bloqueo[x][i]])
			{
				dfs(bloqueo[x][i]);
			}
	}
	else
		return;
}
bool buscar(float para)
{
	bloqueo=vector<vector<int>>(r+1);
	visita= vector<bool>(r+2,false);
	for(int i=0;i<g.size();i++)
	{
		for(int e=0;e<g[i].size();e++)
		{
			if(g[i][e].first!=i && g[i][e].second<para)
				bloqueo[i].push_back(g[i][e].first);
		}
	}
	dfs(0);
	if(comp)
		return false;
	else
		return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a,b;
	float w;
	while (1)
	{
		cin >> n >> r;
		if (!n && !r)
			break;
		g = vector<vector<pair<int,float> > > (r+1,vector<pair<int,float> > (r+1,pair<int,float>(0,0)));
		
		puntos = vector<pair<int, int> >(r); 
		for (int i = 0; i < r; i++)
		{
			cin >> a >> b;
			puntos[i].first = a;
			puntos[i].second = b;
		}
		for (int i = 0; i < r; i++)
		{
			g[0][i].first=i+1;
			g[0][i].second = distancia(puntos[i].first, 0, puntos[i].first, puntos[i].second);
		}

		g[0][r].first=r+1;
		g[0][r].second=n;
	
		for (int i = 0; i < r; i++)
		{
			for (int e = 0; e < r; e++)
			{
				g[i + 1][e].first=e+1;
				g[i + 1][e].second = distancia(puntos[i].first, puntos[i].second, puntos[e].first, puntos[e].second);
			}
			g[i+1][r].first=r+1;
			g[i+1][r].second=n-puntos[i].second;
		}
		float lo = 0, hi = n - 1, ans = -1;
		for (int k = 0; k < 29; k++)
		{
			float mid = lo + (hi - lo+1) / 2;
			comp=false;
			if (buscar(mid) == false)
				hi = mid-1;
			else
				lo = mid;
		}
		printf("%.3f\n",lo);
		
	}	
	return 0;
}
