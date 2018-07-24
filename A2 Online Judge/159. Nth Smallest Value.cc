#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> vec(10);
		for(int i=0;i<10;i++) cin>>vec[i];
		sort(vec.begin(),vec.end());
		cout<<vec[1]<<endl;
	}
	return 0;
}