#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int n,t=1;
	while(cin>>n)
	{
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		long long int maxi=0,aux;
		for(int i=0;i<n;i++)
		{
			aux=1;
			for(int e=i;e<n;e++)
			{
				aux*=vec[e];
				maxi=max(aux,maxi);
			}
		}
		cout<<"Case #"<<t++<<": The maximum product is "<<maxi<<"."<<endl<<endl;
	}
	return 0;
}