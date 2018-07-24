#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k;
	while(cin>>k)
	{
		vector<pair<int,int> > pares;
		for(int i=k+1;i<=k*2;i++)
			if((i*k)%(i-k)==0)
				pares.push_back(pair<int,int>((i*k)/(i-k),i));
		cout<<pares.size()<<endl;
		for(int i=0;i<pares.size();i++)
			cout<<"1/"<<k<<" = 1/"<<pares[i].first<<" + 1/"<<pares[i].second<<endl;
	}
	return 0;
}