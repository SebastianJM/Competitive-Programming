
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii; 
typedef vector<int> vi;
vi pset;        
int numSets; 
int n;

void init(int n)
{
	pset = vi(n); for (int i = 0; i < n; i++) pset[i] = i;
}
int findSet(int i)
{
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

priority_queue<iii> edges;

ii mst(int n)
{
	int mstSize = 0;
	int mstCost = 0;
	init(n);
	while (!edges.empty() && mstSize < n - 1)
	{
		iii edge = edges.top();
		edges.pop();
		int x = edge.second.first;
		int y = edge.second.second;
		int w = abs(edge.first);
		if (!isSameSet(x, y))
		{
			unionSet(x, y);
			mstSize++;
			mstCost += w;
		}
		
	}
	return ii(mstSize, mstCost);
}

int main()
{
	map<string,int> mapa;
	int m,q;
	string s,t;
	int j;
	cin >> q;
	while (q--)
	{
		getchar();
		cin >> n >> m;
		int x = 0, a1, a2;
		while (!edges.empty())
			edges.pop();
		for (int i = 0; i < m; i++)
		{
			cin >> s >> t >> j;
			if (mapa.find(s) == mapa.end())
			{
				mapa[s] = x; a1 = x; x++;
			}
			else
				a1 = mapa[s];

			if (mapa.find(t) == mapa.end())
			{
				mapa[t] = x; a2 = x; x++;
			}
			else
				a2 = mapa[t];
			edges.push(iii(-j, ii(a1, a2)));
		}
		ii ans = mst(n);
		cout << ans.second << endl;
		if (q >= 1)
			cout << endl;
	}

	return 0;
}

