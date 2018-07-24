#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 1005
#define pb(x) push_back(x)
#define MAX 100005
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<int, int> ii; // Pair : (Node, Node)
typedef pair<int, ii> iii; // Triple : (Weight, (Node, Node))

vi pset;
int nSets;
void initSet(int n)
{
	nSets = n;
	pset = vi(n, 0);
	for (int i = 0; i < n; i++)
		pset[i] = i;
}
int findSet(int i)
{
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
	if (!isSameSet(i, j))
	{
		nSets--;
		pset[findSet(i)] = findSet(j);
	}
}
int air_cost;
priority_queue<iii> edges; // List of edges
ii mst(int n) // n: Number of nodes
{
	int mstSize = 0; // mst_size: Number of edges of the MST
	int mstCost = 0; // mst_cost: Weight of the MST
	initSet(n); // Initialize Union-Find
	while (!edges.empty() && mstSize < n - 1) // If there are edges..
	{
		iii edge = edges.top(); edges.pop(); // Get the lowest-cost edge
		int x = edge.second.first, y = edge.second.second; // Get nodes
		int w = abs(edge.first); // Get weight
		if (w >= air_cost)
			break;
		if (!isSameSet(x, y)) // If the nodes are not in the same CC..
		{
			unionSet(x, y); // Connect the nodes
			mstSize++; // The tree gains one edge
			mstCost += w; // The weight of the tree increases
		}
	}
	return ii(mstSize, mstCost); // Returns: (Number of edges on MST, Weight)
}

int main()
{
	fastIO;
	int t, n, r, ca = 1, x, y, w;
	cin >> t;
	while (t--)
	{
		cin >> n >> r >> air_cost;
		while (!edges.empty())
			edges.pop();
		for (int i = 0; i<r; i++)
		{
			cin >> x >> y >> w;
			x--; y--;
			edges.push(iii(-w, ii(x, y)));
		}
		ii MST = mst(n);
		int ans = MST.second + nSets * air_cost;
		cout << "Case #" << ca++ << ": " << ans << " " << nSets << "\n";
	}
	return 0;
}
