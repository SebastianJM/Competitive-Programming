#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main() 
{
	fastIO;
	string s;
	set<pair<int,int> > seg;
	pair<int,int> p;
	set<pair<int,int> >::iterator it1,it2;
	int ans=0;
	cin>>s;
	
	int va,vb;
	
	if(s.size()==1)
		seg.insert(make_pair(0,0));
	else
	{
		int i=1;
		va=vb=-1;
		if(s[0]==s[1])
			va=0;
		for(i=1;i<s.size()-1;i++)
		{
			if(s[i]==s[i-1] && s[i]==s[i+1] && va==-1)
			{
				va=i;
			}
			else if(s[i]!=s[i-1] || s[i]!=s[i+1])
			{
				if(va!=-1)
				{
					vb=i-1;
					seg.insert(make_pair(va,vb));
					va=vb=-1;	
				}
					
			}
		}

		if(va!=-1 && s[s.size()-1]==s[s.size()-2])
			seg.insert(make_pair(va,s.size()-1));
		else if(s[s.size()-1]==s[s.size()-2])
			seg.insert(make_pair(s.size()-1,s.size()-1));
		if(seg.size()>1)
			ans++;
		else
		{
			p=*seg.begin();
			if(p.first!=0||p.second!=s.size()-1)
				ans++;
		}
	}
	

	if(seg.size()==0)
		cout<<1<<endl;
	else
	{
		
	
	while(1)
	{
		pair<int,int> a,b;
		bool move=false;
		if(seg.size()>0)
		{
		it1=seg.begin();
		it2=it1;
		it2++;
		set<pair<int,int> > aux;
		a=*it1;
		for(;it2!=seg.end();it2++)
		{
			b=*it2;
			if(s[a.second]!=s[b.first])
			{
				a.second--;
				b.first++;
				move=true;
			}
			
			if(a.first<=a.second)
				aux.insert(a);
			a=b;
			
		}
		
		if(a.first<=a.second)
				aux.insert(a);
		seg=aux;
		if(!move)
			break;
		ans++;	
		}
		if(!move)
			break;
		
		
	}
	
	cout<<ans<<endl;
	}
	return 0;
}