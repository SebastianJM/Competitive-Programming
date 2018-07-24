#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vector<pair<double, double> > points;
int n;
double mul[403][403], h, w;;

vi pset; // pset[i]: Boss of node i

void init(int n)
{
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
		pset[findSet(i)] = findSet(j);
}

bool f(double r)
{
	init(n + 4);
	for (int i = 0; i<n; i++)
		if (r >= points[i].first)
			unionSet(i, n);

	for (int i = 0; i<n; i++)
		if (r >= points[i].second)
			unionSet(i, n + 1);

	for (int i = 0; i<n; i++)
		if (r >= w - points[i].first)
			unionSet(i, n + 2);

	for (int i = 0; i<n; i++)
		if (r >= h - points[i].second)
			unionSet(i, n + 3);

	double rr4 = 4 * r*r;
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++)
			if (mul[i][j] <= rr4)
				unionSet(i, j);

	if (isSameSet(n, n + 1) || isSameSet(n, n + 2) || isSameSet(n + 1, n + 3) || isSameSet(n + 2, n + 3))
		return true;
	return false;
}
int main()
{
	while (1)
	{
		cin >> n >> w >> h;
		if (n == -1) break;
		points = vector<pair<double, double> >(n);
		for (int i = 0; i<n; i++)
			cin >> points[i].first >> points[i].second;
		for (int i = 0; i<n; i++)
			for (int j = i + 1; j<n; j++)
				mul[i][j] = (points[i].first - points[j].first)*(points[i].first - points[j].first) +
				(points[i].second - points[j].second)*(points[i].second - points[j].second);
		double lo = 0.0, hi = 600002.0, ans;
		for (int i = 0; i < 50; i++)
		{
			double mid = (lo + hi) * 0.5;
			if (f(mid)) ans = hi = mid;
			else lo = mid;

		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
