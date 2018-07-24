#include <bits/stdc++.h>

using namespace std;

int main() 
{
	string s;
	vector<int> val;
	int n;
	cin>>n;
	val=vector<int>(n);
	for(int i=0;i<n;i++)
		cin>>val[i];
	getchar();
	int ans;
	bool es=true;
	for(int i=0;i<n;i++)
	{
		ans=0;
		
		getline(cin,s);
		for(int e=0;e<s.length();e++)
			if(s[e]=='a' || s[e]=='e' || s[e]=='i' || s[e]=='o' || s[e]=='u' || s[e]=='y')
				ans++;
		if(val[i]!=ans)
			es=false;
	}
	if(es)	cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
	return 0;
}