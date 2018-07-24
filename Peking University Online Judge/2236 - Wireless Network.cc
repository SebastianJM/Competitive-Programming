#include <vector>
#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
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
void initSet(int n) { pset = vi(n); for (int i = 0; i < n; i++) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
pair<double, double> pos[N];
bool connected[N];
inline double dist(pair<double, double> x, pair<double, double> y)
{
	return sqrt((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second));
}
int main()
{
	fastIO;
	int n, d, x, y;
	char t;
	cin >> n >> d;
	memset(connected, false, sizeof connected);
	for (int i = 0; i<n; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	initSet(n);
	while (cin >> t)
	{
		if (t == 'O')
		{
			cin >> x;
			x--;
			if (!connected[x])
			{
				connected[x] = true;
				for (int i = 0; i<n; i++)
				{
					if (x != i && connected[i] && dist(pos[i], pos[x]) <= d)
						unionSet(x, i);
				}
			}
		}
		else
		{
			cin >> x >> y;
			x--; y--;
			if (isSameSet(x, y))
				cout << "SUCCESS\n";
			else
				cout << "FAIL\n";
		}
	}
	return 0;
}