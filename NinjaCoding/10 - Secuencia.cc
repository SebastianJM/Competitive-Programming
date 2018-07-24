#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{ 
	int t,a,b,min,max;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a>b)
		{
			max=a;
			min=b;
		}
		else
		{
			max=b;
			min=a;
		}

		for(int i=min;i<=max;i++)
		{
				cout<<i<<" ";			
		}
		
		cout<<endl;
	}
    return 0;
}