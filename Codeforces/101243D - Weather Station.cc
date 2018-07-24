#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	set<string> mp;
	mp.insert("NW");
	mp.insert("NE");
	mp.insert("SE");
	mp.insert("SW");
	
	string s,t;
	int ans=1;
	cin>>s;
	//cout<<"123"<<s<<endl;
	for(int i=0;i<s.size()-1;i++)
	{
		t=s[i];
		t+=s[i+1];
		//cout<<t<<endl;
		if(mp.find(t)!=mp.end())
		{
			ans*=2;
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}