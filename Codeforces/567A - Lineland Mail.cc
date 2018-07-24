#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<vec[1]-vec[0]<<" "<<vec[n-1]-vec[0]<<endl;
	for(int i=1;i<n-1;i++)
	{
		cout<<min(vec[i]-vec[i-1],vec[i+1]-vec[i])<<" "<<max(vec[i]-vec[0],vec[n-1]-vec[i])<<endl;
	}
	cout<<vec[n-1]-vec[n-2]<<" "<<vec[n-1]-vec[0]<<endl;
	
	return 0;
}