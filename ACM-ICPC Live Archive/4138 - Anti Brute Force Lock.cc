#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

#define INF 20000000
typedef pair<int, int> ii; // Par      : (Nodo, Nodo)  
typedef pair<int, ii> iii; // Triplete : (Peso, (Nodo, Nodo))
typedef vector<int> vi;

// Union-Find
vi pset;
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

// Kruskal
priority_queue<iii> edges; // Lista de aristas

ii mst(int n) // n: Número de nodos
{
	int mstSize = 0;  // mstSize: Número de aristas en el MST
	int mstCost = 0;  // mstCost: Peso del MST
	init(n);          // Inicializar Union-Find
	while (!edges.empty() && mstSize < n - 1) // Procesar aristas..
	{
		iii edge = edges.top(); edges.pop(); // Traer menor arista
		int x = edge.second.first;  // Nodo x
		int y = edge.second.second; // Nodo y
		int w = abs(edge.first);    // Peso entre x e y
		if (!isSameSet(x, y)) // Si los nodos están en diferentes CC
		{
			unionSet(x, y); // Conectar los sets
			mstSize++;      // El MST gana una arista
			mstCost += w;   // El peso del MST aumenta en w
		}
	}
	return ii(mstSize, mstCost); // (Número de aristas, Peso)
}

int dist(string s1, string s2)
{
	int n = 0;
	for (int i = 0; i<4; i++)
		n += min(min(s1[i] - '0' + 10 - (s2[i] - '0'), s2[i] - '0' + 10 - (s1[i] - '0')), abs((s1[i] - '0') - (s2[i] - '0')));
	return n;
}

int main()
{
	int n, t;
	cin >> t;
	while (t--)
	{
		while (!edges.empty())
			edges.pop();
		cin >> n;
		vector<string> vec = vector<string>(n);	
		for (int i = 0; i<n; i++)
			cin >> vec[i];

		for (int i = 0; i<n - 1; i++)
			for (int e = i + 1; e<n; e++)
				edges.push(iii(-dist(vec[i], vec[e]), ii(i, e)));

		ii ans = mst(n);
		int mini = 100000000;
		for (int i = 0; i < n; i++)
			if (mini>dist("0000", vec[i]))
				mini = dist("0000", vec[i]);
		cout << ans.second+mini << endl;
	}
	return 0;
}