#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x) 
#define N 1003
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
 
vi pset; // pset[i]: Boss of node i
int nSets; // Total number of sets
void init(int n) // n: Number of nodes
{
	nSets = n; // There are n sets
	pset = vi(n, 0); // Assign capacity for n nodes
	for(int i = 0; i < n; i++) // For each node i..
		pset[i] = i; // Node i is its own boss
}
int findSet(int i) // Returns the final boss of node i
{
	return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) // Checks if two nodes belong to the same set
{
	return findSet(i) == findSet(j); // Check if nodes have the same boss
}
void unionSet(int i, int j) // Joins the sets of node i and node j
{
	//cout << "uning " << i << " " << j << endl;
	if(!isSameSet(i, j)) // If the nodes belong to different sets..
	{
		nSets--; // After merging two sets, the total number decreases in one
		// Keep boss of j as the main one...
		pset[findSet(i)] = findSet(j); // Boss of i changes to boss of j
	}
}
vector<pair<int, pair<int, int>>> g;
int main() {
	fastIO;
	int n, m, c, k, a, b, w, con = 0;
	cin >> n >> m >> c >> k;
	g = vector<pair<int, pair<int, int>>>(m);
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		a--;
		b--;
		g[i].first = w;
		g[i].second.first = a;
		g[i].second.second = b;
	}
	sort(g.begin(), g.end());
	for(int i = 0; i < m && con < c; i++) {
		init(n);
		for(int j = 0; j < m; j++) {
			if(i != j)
				unionSet(g[j].second.first, g[j].second.second);
		}
		if(nSets == 1) {
			cout << g[i].second.first + 1 << " " << g[i].second.second + 1 << "\n";
			con++;
		}
	}
	return 0;
}