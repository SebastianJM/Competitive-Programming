#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>


using namespace std;

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi pset;     // pset[i]: Jefe del nodo i
int numSets; // Número de componentes conexas

void init(int n) // n: Número de nodos
{
  numSets = n;               // Al inicio hay N sets
  pset = vi(n, 0);           // Asignar n casilleros al vector
  for(int i = 0; i < n; i++) // Para cada nodo i..
    pset[i] = i;             // El nodo i es su propio jefe
}

int findSet(int i) // i: Nodo
{
  return (pset[i] == i)? i : (pset[i] = findSet(pset[i])); 
}

bool isSameSet(int i, int j) // i,j: Nodos
{
  return findSet(i) == findSet(j); 
}

void unionSet(int i, int j) // i,j: Nodos
{
  if(!isSameSet(i, j)) // Si los nodos son de diferentes sets..
  {
    numSets--; // Al unir dos sets, el total disminuye en uno
    // El jefe del nodo j se impondrá
    pset[findSet(i)] = findSet(j); // El set i tiene nuevo jefe
  }
}

int main()
{

	int t,p;
	char c;
	string s;
	cin>>t;
	p=t;
	while(t--)
	{
		cin>>c;
		init(c-'A'+1);
		getchar();
		while(1)
		{
			getline(cin,s);
			if(s.size()==0)
				break;
			unionSet(s[0]-'A',s[1]-'A');
		}
		if(p!=t+1)
			cout<<endl;
		cout<<numSets<<endl;
	}
    return 0;
}
