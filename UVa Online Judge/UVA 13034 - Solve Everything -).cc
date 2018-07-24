#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,a;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		bool ans=true;
		for(int k=0;k<13;k++)
		{
			cin>>a;
			if(!a)
				ans=false;
		}
		cout<<"Set #"<<i<<": "<<(ans?"Yes":"No")<<endl;
	}
	return 0;
}