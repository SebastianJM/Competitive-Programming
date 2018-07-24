#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> vec[1000001];
int main()
{
	int t, n,pos,num,aux;
	
	while (cin >> n >> t)
	{
		memset(vec,0,sizeof vec);
		for(int i=1;i<=n;i++)
		{
			cin>>aux;
			vec[aux].push_back(i);
		}
		for(int i=0;i<t;i++)
		{
			cin>>pos>>num;
			if(vec[num].size()>pos-1)
				cout<<vec[num][pos-1]<<endl;
			else
				cout<<0<<endl;
		}
	
	}
	return 0;
}