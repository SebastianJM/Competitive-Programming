#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	string q;
	set<string> s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s.clear();
		for(int i=0;i<n;i++)
		{
			cin>>q;
			s.insert(q);
		}
		cout<<s.size()<<endl;
	}
	return 0;
}