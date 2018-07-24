#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef pair<int, double> ii;
typedef pair<double, ii> iii;
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
	double mstCost = 0.0;
	init(n);
	while (!edges.empty() && mstSize < n - 1)
	{
		iii edge = edges.top();
		edges.pop();
		int x = edge.second.first;
		int y = edge.second.second;
		double w = abs(edge.first);
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
	int m;
	int j;
	int vx[1001];
	int vy[1001];
	double dis;
	while (true)
	{
		cin >> n;
		if (n == 0)
			return 0;
		while (!edges.empty())
			edges.pop();
		for (int i = 0; i < n; i++)
			cin >> vx[i] >> vy[i];
		for (int i = 0; i < n - 1; i++)
			for (int e = i + 1; e < n;e++)
				edges.push(iii(-(sqrt(pow(vx[i]-vx[e],2)+pow(vy[i]-vy[e],2))), ii(i, e)));
		
		ii ans = mst(n);
		printf("%.2lf\n", ans.second);
	}

	return 0;