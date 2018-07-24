#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;cin>>n;
	vector<int> vec=vector<int>(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	sort(vec.begin(),vec.end());
	long long suma=0;
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(suma<=vec[i])
		{
			suma+=vec[i];
			res++;
		}
	}
	cout<<res;
	return 0;
}

