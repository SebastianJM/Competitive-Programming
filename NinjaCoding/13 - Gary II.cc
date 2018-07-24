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
		aux=0;
		sum=0;
		while(aux<b)
		{
			aux+=a;
			sum++;
			if(aux>=b)
			{
				cout<<sum<<endl;
				break;
			}
			aux-=(aux*0.1);		
		}
		
	}
    return 0;
}