#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q,a,c=1;
	vector<int> v;
	while(1)
	{
		cin>>n>>q;
		if(!n && !q)
			break;
		v=vector<int>(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		cout<<"CASE# "<<c++<<":"<<endl;
		for(int i=0;i<q;i++)
		{
			cin>>a;
			int pos=int(lower_bound(v.begin(),v.end(),a)-v.begin());
			//cout<<pos<<endl;
			if(v[pos]==a)
				cout<<a<<" found at "<<pos+1<<endl;
			else
				cout<<a<<" not found"<<endl;
		}
	}
	return 0;
}
