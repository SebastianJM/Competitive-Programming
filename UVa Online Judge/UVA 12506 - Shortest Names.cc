#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

struct Trie
{
	int g[MAX]['z'-'a'+1];
	int div[MAX];
	int n;
	Trie(){ clear();}
	void clear()
	{
		memset(g[0],-1,sizeof g[0]);
		n=0;
	}
	void insertar(string s)
	{
		int cur=0;
		for(int i=0;i<s.length();i++)
		{
			int c=s[i]-'a';
			if(g[cur][c]==-1)
			{
				g[cur][c]=++n;
				memset(g[n],-1,sizeof g[n]);
				div[n]=0;
				div[cur]++;
			}
			cur=g[cur][c];
		}
	}
	int pref(string s)
	{
		int cur=g[0][s[0]-'a'];
		int ans=1;
		bool last=false;
		for(int i=1;i<s.length();i++)
		{
			if(div[cur]>1)
				last=true;
			else if(last)
			{
				ans=i;
				last=false;
			}		
			cur=g[cur][s[i]-'a'];
		}
		if(last)
			ans=s.length();
		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	string s;
	vector<string> vs;
	Trie arbol;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vs.clear();
		arbol.clear();
		for(int i=0;i<n;i++)
		{
			cin>>s;
			vs.push_back(s);
			arbol.insertar(s);
		}
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=arbol.pref(vs[i]);
		cout<<ans<<"\n";
	}
	return 0;
}