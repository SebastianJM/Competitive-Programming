#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int n;
	int can,res(0);
	cin>>n;
	cin>>can;
	vec=vector<int>(n-1);
	for(int i=0;i<n-1;i++)
		cin>>vec[i];
	for(;can<=max_element(vec.begin(),vec.end())[0]--;can++)
		res++;
	cout<<res;
	return 0;
}