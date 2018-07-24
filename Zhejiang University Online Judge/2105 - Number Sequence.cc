#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;
void Funcion(int a,int b)
{
	for(int i=3;i<49;i++)
		vec[i]=(a*vec[i-1]+b*vec[i-2])%7;
}
int main()
{
	int a,b,n;
	while(1)
	{
		cin>>a>>b>>n;
		if(a==0 && b==0 & n==0)
			return 0;
		vec=vector<int>(49);
		vec[1]=1;
		vec[2]=1;
		Funcion(a,b);
		cout<<vec[n%48]<<endl;
	}
	return 0;
}