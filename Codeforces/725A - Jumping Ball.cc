#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,ans=0;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n && s[i]=='<';i++)
		ans++;
	for(int i=n-1;i>=0 && s[i]=='>';i--)
		ans++;
	cout<<ans<<endl;
	return 0;
}