#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;


struct Trie
{
	int g[MAX][26];
	int div[MAX];
	bool leaf[MAX];
	int n;

	Trie() { clear(); }

	void clear()
	{
		n = 0;
		memset(g[0], -1, sizeof g[0]);
		div[0] = 0;
		leaf[0] = false;
	}
	void insert(string s)
	{
		int cur = 0;
		for (int i = 0; i < (int)s.size(); i++)
		{
			int c = s[i] - 'a';
			if (g[cur][c] == -1)
			{
				g[cur][c] = ++n;
				memset(g[n], -1, sizeof g[n]);
				div[n] = 0;
				leaf[n] = false;
				div[cur]++;
			}
			
			cur = g[cur][c];
		}
		leaf[cur] = true;
	}
	int keystrokes(string s)
	{
		int cur = g[0][s[0]-'a'], keys = 1;
		for (int i = 1; i<(int)s.size(); i++)
		{
			int c = s[i] - 'a';
			if (div[cur]>1||leaf[cur])
				keys++;
			cur = g[cur][c];
		}
		return keys;
	}
};
Trie arbol;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;

	while (cin >> n)
	{
		arbol.clear();
		vector<string> vs;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			vs.push_back(s);
			arbol.insert(s);
		}
		double suma = 0;
		for (int i = 0; i < n; i++)
			suma += arbol.keystrokes(vs[i]);
		printf("%.2f\n", suma / n);
	}

	return 0;
}