#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{ 
	int t;
	float a,b,aux;
	int sum;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		a/=2;
		b-=a;
		aux=0;
		sum=0;
		while(aux<b)
		{
			aux+=a;
			sum++;
		}
		cout<<sum<<endl;
	}
    return 0;
}