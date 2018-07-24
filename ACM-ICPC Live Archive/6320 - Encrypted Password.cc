

#include <bits/stdc++.h>

using namespace std;

#define MAX 103

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t,ans,ori[26],cam[26];
	bool is;
	string c,o;
	cin>>t;
	while(t--)
	{
		memset(ori,0,sizeof ori);
		memset(cam,0,sizeof cam);
		cin>>c>>o;
		for(int i=0;i<o.size();i++)
			ori[o[i]-'a']++;
		for(int i=0;i<o.size();i++)
			cam[c[i]-'a']++;
		is=true;
		for(int i=0;i<26;i++)
			if(ori[i]!=cam[i])
			{
				is=false;
				break;
			}
		if(is)
		{
			cout<<"YES\n";
			continue;
		}
		for(int i=o.size();i<c.size();i++)
		{
			cam[c[i-o.size()]-'a']--;
			cam[c[i]-'a']++;
			is=true;
			for(int i=0;i<26;i++)
				if(ori[i]!=cam[i])
				{
					is=false;
					break;
				}
			if(is)
			{
				cout<<"YES\n";
				break;
			}
		}
		//cout<<is<<endl;
		if(!is)
			cout<<"NO\n";
			
		
	}
	return 0;
}
