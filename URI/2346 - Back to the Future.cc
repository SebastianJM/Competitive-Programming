#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,r,a,b,u,v;
	set<int> g[100004];
	set<pair<int,int> > s;
	set<int>::iterator it;
	set<pair<int,int> >::iterator it_beg,it_end;
	cin>>n>>r>>a>>b;
	for(int i=0;i<r;i++)
	{
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i=1;i<=n;i++)
		s.insert(make_pair(g[i].size(),i));
	it_beg=s.begin();
	it_end=s.end();
	it_end--;
	while(s.size()>0 && (s.size()-(*it_end).first-1<b||(*it_beg).first<a))
	{
		while(s.size()>0 && (*it_beg).first<a)
		{
			for(it=g[(*it_beg).second].begin();it!=g[(*it_beg).second].end();it++)
			{
				s.erase(make_pair(g[*it].size(),*it));
				g[*it].erase((*it_beg).second);
				s.insert(make_pair(g[*it].size(),*it));
				
			}
			s.erase(it_beg);
			it_beg=s.begin();
		}
	
		while(s.size()>0 && (s.size()-(*it_end).first-1<b))
		{
			for(it=g[(*it_end).second].begin();it!=g[(*it_end).second].end();it++)
			{
				s.erase(make_pair(g[*it].size(),*it));
				g[*it].erase((*it_end).second);
				s.insert(make_pair(g[*it].size(),*it));
			}
			s.erase(it_end);
			if(s.size()>0)
			{
				it_end=s.end();
				it_end--;
			}
		}
	}
	cout<<s.size()<<endl;
	return 0;
}