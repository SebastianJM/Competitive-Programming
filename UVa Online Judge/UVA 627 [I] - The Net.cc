#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

#define INF 20000000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
vvii g;
vi dist;
vi preva;
int n;

void init()
{
	preva = vi(n, -1);
	dist = vi(n, INF);
}
void dijkstra(int s)
{
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dist[v] >= d)
			for (int i = 0; i < (int)g[v].size(); i++)
			{
				int u = g[v][i].second;
				int w = g[v][i].first;
				if (dist[v] + w < dist[u])
				{
					dist[u] = dist[v] + w;
					preva[u] = v;
					pq.push(ii(dist[u], u));
				}
			}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a,b,ori,des;
	string s;
	while (cin >> n)
	{
		//getchar();
		g = vvii(n);
		if(n<10)
			for (int i = 0; i < n; i++)
			{
				cin >> s;
				
				for (int p = 2; p < s.length(); p++)
					if (s[p] != ',')
						g[i].push_back(ii(1, s[p] - '0'-1));
			}
		else
			for (int i = 0; i < n; i++)
			{
				cin >> s;
				int con=0;
				
				for (int p = i<9?2:3; p < s.length(); p++)
					if(s[p]!=',')
					{
						if(p==s.length()-1)
						{
							if(con>0)
								g[i].push_back(ii(1,9));
							else
								g[i].push_back(ii(1, s[p] - '0'-1));
							con=0;
						}
						else
							con++;					
					}
					else
						if(con>1)
						{
							g[i].push_back(ii(1,9));
							con=0;
						}
						else
						{
							g[i].push_back(ii(1, s[p-1] - '0'-1));	
							con=0;
						}

			}
		cin >> b;
		cout<<"-----"<<endl;
		for (int i = 0; i < b; i++)
		{
			cin >> ori>>des;
			ori--;
			des--;
			init();
			dijkstra(ori);
			vector<int> vec;
			vec.push_back(des);
			int tipo = 0;
			while (des != ori)
			{
				if (preva[des] == -1)
				{
					tipo = 1;
					break;
				}
				des = preva[des];

				vec.push_back(des);
			}
			
			if (tipo)
				cout << "connection impossible" << endl;
			else
			{
				for (int i = vec.size() - 1; i >= 0; i--)
				{
					cout << vec[i]+1;
					if (i != 0)
						cout << " ";
				}
				cout << endl;
			}
		}
		
	}
	
	return 0;

}
