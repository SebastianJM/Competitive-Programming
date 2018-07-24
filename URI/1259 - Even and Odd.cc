#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned int n,a;
	vector<int> par,inpar;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a%2==1)
			inpar.push_back(a);
		else
			par.push_back(a);
	}
	sort(inpar.rbegin(),inpar.rend());
	sort(par.begin(),par.end());
	for(int i=0;i<par.size();i++)
		cout<<par[i]<<endl;
	for(int i=0;i<inpar.size();i++)
		cout<<inpar[i]<<endl;
	return 0;
}
