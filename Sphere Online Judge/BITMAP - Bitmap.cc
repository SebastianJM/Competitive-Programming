#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 200
#define MAX 100000004
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;

bool visit[N][N];
int dis[N][N], n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void propagate(int y, int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	memset(visit, false, sizeof visit);
	visit[y][x] = true;

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i<4; i++)
			if (y + dy[i] >= 0 && y + dy[i]<n && x + dx[i] >= 0 && x + dx[i]<m && dis[y][x]<(dis[y + dy[i]][x + dx[i]] - 1) && !visit[y + dy[i]][x + dx[i]])
			{
				dis[y + dy[i]][x + dx[i]] = dis[y][x] + 1;
				visit[y + dy[i]][x + dx[i]] = true;
				q.push(make_pair(y + dy[i], x + dx[i]));
			}
	}

}
int main()
{
	fastIO;
	int t;
	char mat[N][N];
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				dis[i][j] = 100000;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> mat[i][j];
				if (mat[i][j] == '1')
				{
					dis[i][j] = 0;
					propagate(i, j);
				}
			}
		}
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (j)
					cout << " ";
				cout << dis[i][j];
			}
			cout << endl;
		}

	}
	return 0;
}