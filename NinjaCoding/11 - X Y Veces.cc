#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{ 
	int t,a,b;
	vector<long long> vec;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		vec=vector<long long>(b);
		vec[0]=a;
		for(int i=1;i<b;i++)
			vec[i]=10*vec[i-1];
		for(int i=0;i<b;i++)
		{
			if(i!=b-1)
				cout<<vec[i]<<" ";
			else
				cout<<vec[i];
		}
		cout<<endl;
	}
    return 0;
}