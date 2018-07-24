#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b,ans;
	bool is=false;
	cin>>a>>b;
	ans="";
	int e=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>=b[e] && i>0)
		{
			ans.push_back(b[e]);
			is=true;
			break;
		}
		ans.push_back(a[i]);
	}
	if(!is)
		ans.push_back(b[0]);
	cout<<ans<<endl;
	return 0;
}