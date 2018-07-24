#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q,a;
	vector<int> v;
	while(cin>>n)
	{
		
		v=vector<int>(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cin>>q;
		for(int i=0;i<q;i++)
		{
			cin>>a;	
			int pos_may=int(lower_bound(v.begin(),v.end(),a+1)-v.begin());
			int pos_min=int(upper_bound(v.begin(),v.end(),a-1)-v.begin());
			//cout<<"---- "<<pos_min<<" "<<pos_may<<endl;
			if(pos_min>0 && v[pos_min-1]!=a)
				cout<<v[pos_min-1]<<" ";
			else
				cout<<"X ";
			if(pos_may!=v.size())
				cout<<v[pos_may];
			else
				cout<<"X";
			cout<<endl;
		}
	}
	return 0;
}