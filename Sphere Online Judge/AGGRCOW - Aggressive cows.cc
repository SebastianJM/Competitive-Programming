#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
vector<int> establos;
int N,C;
void busqueda()
{
	int lo = 0, hi = 1000000000;
	while(lo < hi) {
 
	  int mid = lo + (hi-lo+1) / 2; 
 
	  int asignados = 1, ultimo = 0;
	  for(int i = 1; i < N; i++)
	    if(establos[ultimo] + mid <= establos[i])
	    {
	      ultimo = i;
	      asignados++;
	    } 
 
	  if(asignados >= C)
	    lo = mid;
	   else
	    hi = mid - 1;  
	}
	cout << lo << '\n';
}
int main()
{
	int aux;
	cin>>aux;
	while(aux--)
	{
		cin>>N>>C;
		establos=vector<int>(N);
		for(int i=0;i<N;i++)
			cin>>establos[i];
		sort(establos.begin(),establos.end());
		busqueda();
	}
	return 0;
} 