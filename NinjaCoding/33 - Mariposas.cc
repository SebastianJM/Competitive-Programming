#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int main()
{
	int matriz[204][204];
	int n,f,c;
	set<int> ss;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int e=0;e<n;e++)
			cin>>matriz[i][e];
	for(int i=0;i<2*n;i++)
	{
		cin>>f>>c;
		ss.insert(matriz[f-1][c-1]);
	}
	cout<<ss.size()<<endl;
	return 0;
}