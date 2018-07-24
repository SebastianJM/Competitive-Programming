#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005; // M�ximo n�mero de nodos
bool rep;
struct Trie
{
	int g[MAX][10]; // g: Trie
	bool word[MAX];
	int n;          // n: �ltimo nodo

	Trie() { clear(); }

	void clear() // Limpia el trie
	{
		n = 0;     // Ra�z 
		memset(g[0], -1, sizeof g[0]); // Inicializar el nodo ra�z
		word[0]=false;
	}

	void insert(string s) // s: String a insertar 
	{
		int cur = 0; // Empezar en la ra�z
		for (int i = 0; i < (int)s.size(); i++) // Por cada caracter en s..
		{
			int c = s[i] - '0'; // Obtener letra s[i]
			if (g[cur][c] == -1) // Si el vecino para la letra "c" no existe..
			{
				g[cur][c] = ++n;  // Asignar un nuevo nodo
				memset(g[n], -1, sizeof g[n]); // Inicializar el nuevo nodo
				word[n] = false;
			}
			else
			{
				if ((i == (int)s.size()-1)|| word[g[cur][c]])
					rep = true;
			}
			cur = g[cur][c]; // Ir al siguiente nodo
		}
		word[cur] = true;
	}
};

int main()
{
	int t, n;
	string s;
	cin >> t;
	while (t--)
	{
		Trie arbol;
		rep=false;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			if (!rep)
				arbol.insert(s);
		}
		rep ? cout << "NO" : cout << "YES";
		cout << endl;
	}
	return 0;
}