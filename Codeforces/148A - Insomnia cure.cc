#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dragones;

void Llenar(int escala)
{
	for(int i=escala;i<dragones.size();i+=escala)
		dragones[i]++;
}
int main()
{
	int k,l,m,n,d;
	cin>>k>>l>>m>>n>>d;
	if(k==1||l==1||m==1||n==1)
	{
		cout<<d;
		return 0;
	}
	dragones=vector<int>(d+1,0);
	Llenar(k);
	Llenar(l);
	Llenar(m);
	Llenar(n);
	cout<<d-count(dragones.begin()+1,dragones.end(),0);

	return 0;
}