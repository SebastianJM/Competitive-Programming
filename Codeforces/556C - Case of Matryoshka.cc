#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int n;
int r(0);
int res(0);
int main()
{
	int q,a,ant,rec;
	cin>>n>>q;
	vec=vector<int>(n,-1);
	vector<int> aux;
	for(int k=0;k<q;k++)
	{
		cin>>a;
		ant=rec=-1;
		cin>>ant;
		for(int e=1;e<a;e++)
		{
			cin>>rec;
			vec[ant-1]=rec-1;
			ant=rec;
		}
	}
	for(int e=0;e<n;e++)
	{
		if(vec[e]==e+1)
			r++;
		else		
			break;	
	}
	for(int i=r;i<n;i++)
		if(vec[i]!=-1)
			res++;
	res+=(n-r-1);
	cout<<res;
	return 0;
}
