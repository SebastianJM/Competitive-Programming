#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii; // Par      : (Nodo, Nodo)  
typedef pair<int, ii> iii; // Triplete : (Peso, (Nodo, Nodo))

// Union-Find
vi pset;
vi plants;
int s,d,k;

void init(int n) 
{ pset = vi(n); for(int i = 0; i < n; i++) pset[i] = i; }
int findSet(int i) 
{ return (pset[i] == i)? i : (pset[i]= findSet(pset[i]));}
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
bool isSamePlant(int i)
{
	for(int q=0;q<k;q++)
		if(isSameSet(i,plants[q]))
			return true;
	return false;
}
// Kruskal
priority_queue<iii> edges; // Lista de aristas

ii mst(int n) // n: Número de nodos
{  
  int mstSize = 0;  // mstSize: Número de aristas en el MST
  int mstCost = 0;  // mstCost: Peso del MST
  init(n);          // Inicializar Union-Find
  while(!edges.empty() && mstSize < n - k) // Procesar aristas..
  {
    iii edge = edges.top(); edges.pop(); // Traer menor arista
    int x = edge.second.first;  // Nodo x
    int y = edge.second.second; // Nodo y
    int w = abs(edge.first);    // Peso entre x e y
	if(((!isSamePlant(x) && isSamePlant(y))||(isSamePlant(x) && !isSamePlant(y))||(!isSamePlant(x) && !isSamePlant(y))) && !isSameSet(x, y)) // Si los nodos están en diferentes CC
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
	int n,t,a,b,c;
	cin>>n;
	t=0;
	while(t<n)
	{
		cin>>s>>d>>k;
		while(!edges.empty())
		 edges.pop();
		plants=vi(k);
		for(int i=0;i<k;i++)
		{
			cin>>plants[i];
			plants[i]--;
		}
		for(int i=0;i<d;i++)
		{
			cin>>a>>b>>c;
			// Almacenar aristas
			edges.push(iii(-c, ii(a-1, b-1))); 
		}
		ii ans=mst(s);
		cout<<"Case #"<<t+1<<": "<<ans.second<<endl;
		t++;
	}
	return 0;
}