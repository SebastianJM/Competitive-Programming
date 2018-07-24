#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii; // Par      : (Nodo, Nodo)  
typedef pair<int, ii> iii; // Triplete : (Peso, (Nodo, Nodo))

// Union-Find
vi pset;
void init(int n) 
{ pset = vi(n); for(int i = 0; i < n; i++) pset[i] = i; }
int findSet(int i) 
{ return (pset[i] == i)? i : (pset[i]= findSet(pset[i]));}
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

// Kruskal
priority_queue<iii> edges; // Lista de aristas

ii mst(int n) // n: Número de nodos
{  
  int mstSize = 0;  // mstSize: Número de aristas en el MST
  int mstCost = 0;  // mstCost: Peso del MST
  init(n);          // Inicializar Union-Find
  while(!edges.empty() && mstSize < n - 1) // Procesar aristas..
  {
    iii edge = edges.top(); edges.pop(); // Traer menor arista
    int x = edge.second.first;  // Nodo x
    int y = edge.second.second; // Nodo y
    int w = abs(edge.first);    // Peso entre x e y
    if(!isSameSet(x, y)) // Si los nodos están en diferentes CC
    {  
      unionSet(x, y); // Conectar los sets
      mstSize++;      // El MST gana una arista
      mstCost += w;   // El peso del MST aumenta en w
    }
  }
  return ii(mstSize, mstCost); // (Número de aristas, Peso)
}


int main()
{
	int cc,q,a,b,c,su;
	while(cin>>cc>>q)
	{
		if(!cc && !q)
			return 0;
		while(!edges.empty())
			edges.pop();
		su=0;
		for(int i=0;i<q;i++)
		{
			cin>>a>>b>>c;
			edges.push(iii(-c,ii(a,b)));
			su+=c;
		}
		cout<<su-mst(cc).second<<endl;
	}
	return 0;
}