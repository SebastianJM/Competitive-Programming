#include <bits/stdc++.h>

using namespace std;


int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,a;
	char c;
	cin>>n;

	set<pair<int,int> > s;
	for(int i=1;i<n-1;i++)
	{
		cin>>c>>a;
		if(c=='d')
			s.insert(make_pair(a,i));
		else
			while(s.size()>=a)
				s.erase(s.begin());
	}
	cin>>c>>a;
	if(a>s.size())
		cout<<-1<<endl;
	else
	{
		long long ans=0;
		set<int> up;
		for(set<pair<int,int> >::iterator it=s.begin() ;it!=s.end();it++)
		{
			ans+=(*it).first;
			up.insert((*it).second+1);
			
		}
		cout<<ans<<endl;
		cout<<up.size()<<endl;
		bool q=false;
		for(set<int>::iterator it=up.begin();it!=up.end();it++)
		{
		
			if(q)
				cout<<" ";
			q=true;
			cout<<(*it);
		}
	}

	return 0;
}