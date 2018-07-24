#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n,suma(0),cog(0),total(0);
	cin>>n;
	vector<int> vec=vector<int>(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
		suma+=vec[i];
	}
	sort(vec.rbegin(),vec.rend());
	for(int i=0;i<=n;i++)
	{
		if(cog>suma)
		{
			cout<<total;
			return 0;
		}
		suma-=vec[i];
		cog+=vec[i];
		total++;
	}
	return 0;
}
