#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <vector>
using namespace std;

int vec[100005];
int real[100005];

int main()
{
	memset(vec,0,sizeof vec);
	vector<int> repetidos;
	vector<int> falta;
	int n,aux;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>aux;
		if(aux>n||vec[aux]>0)
		{
			repetidos.push_back(i);
		}
		else 
		{
			vec[aux]++;
			real[i]=aux;
		}
	}
	for(int i=1;i<=n;i++)
		if(vec[i]==0)
			falta.push_back(i);
	if(repetidos.size()>0)
	{
		for(int i=0;i<repetidos.size()-1;i++)
		{
			real[repetidos[i]]=falta[falta.size()-1];
			falta.pop_back();
		}	
		real[repetidos[repetidos.size()-1]]=falta[0];
	}
	for(int i=1;i<=n;i++)
		cout<<real[i]<<" ";

	return 0;
}