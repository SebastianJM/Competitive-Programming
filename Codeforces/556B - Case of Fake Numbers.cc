#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;
int n;
void Iteracion()
{
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			if(vec[i]+1>=n)
				vec[i]=0;
			else
				vec[i]++;
		}
		else
		{
			if(vec[i]-1<0)
				vec[i]=n-1;
			else
				vec[i]--;
		}
	}
}
bool Comprobar()
{
	for(int i=0;i<n;i++)
		if(vec[i]!=i)
			return false;
	return true;
}
int main()
{
	
	
	cin>>n;
	vec=vector<int>(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	for(int i=0;i<2*n;i++)
	{
		if(Comprobar())
		{
			cout<<"Yes";
			return 0;
		}
		Iteracion();
	}
	cout<<"No";
	return 0;
}