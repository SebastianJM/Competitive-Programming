#include <bits/stdc++.h>

using namespace std;

set<string> s;
string a,ss="ac ag al am ar as at au b ba be bh bi bk br c ca cd ce cf cl cm cn co cr cs cu db ds dy er es eu f fe fl fm fr ga gd ge h he hf hg ho hs i in ir k kr la li lr lu lv md mg mn mo mt n na nb nd ne ni no np o os p pa pb pd pm po pr pt pu ra rb re rf rg rh rn ru s sb sc se sg si sm sn sr ta tb tc te th ti tl tm u v w xe y yb zn zr";
bool visit[50005];
bool rec(int desde,int hasta)
{
	visit[desde]=true;
	if(hasta>a.size()-1)
		return false;
	
	if(s.find(a.substr(desde,hasta-desde+1))==s.end())
		return false;

	if(hasta>=a.size()-1)
		return true;
	
	
	if(!visit[hasta+1] && (rec(hasta+1,hasta+1)||rec(hasta+1,hasta+2)))
		return true;
	
	return false;
}
int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	for(int i=0;i<ss.size();i++)
	{
		if(ss[i]==' ')
			i++;
		int ant=i;
		a.clear();
		while(ss[i]!=' ' && i<ss.size())
		{
			a.push_back(ss[i]);
			i++;
			
		}
		s.insert(a);
	}

	int n;
	cin>>n;
	while(n--)
	{
		cin>>a;
		memset(visit,0,sizeof visit);
		if(rec(0,0))
		{
			cout<<"YES"<<endl;
			continue;
		}
		memset(visit,0,sizeof visit);
		if(rec(0,1))
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	
	return 0;
}