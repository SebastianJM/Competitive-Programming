#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vector<string> > lev;
vector<pair<string,int> > v;
int c;
void rec(int l)
{
	//cout<<0<<endl;
	int t=c;
	if(lev.size()<=l)
		lev.push_back(vector<string>());
	lev[l].push_back(v[c++].first);
	for(int i=0;i<v[t].second;i++)
		rec(l+1);
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string::size_type sz;
	string s,a;
	cin>>s;
	
	c=0;
	for(int i=0,it=0;i<s.size();i++)
	{
		a.clear();
		while(s[i]!=',')
			a.push_back(s[i++]);
		v.push_back(make_pair(a,0));
		i++;
		a.clear();
		while(s[i]!=',' && i<s.size())
			a.push_back(s[i++]);
		v[it].second=stoi (a,&sz);
		it++;
	}
	
	for(c=0;c<v.size();)
	{
		rec(0);
	}
	
	cout<<lev.size()<<endl;
	for(int i=0;i<lev.size();i++)
	{
		bool pri=true;
		
		for(int j=0;j<lev[i].size();j++)
		{
			if(!pri)
				cout<<" ";
			pri=false;
			cout<<lev[i][j];
		}
		cout<<endl;
	}
	return 0;
}