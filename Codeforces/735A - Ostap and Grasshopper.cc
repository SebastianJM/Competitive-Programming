#include <bits/stdc++.h>

using namespace std;

int main() 
{
	string s;
	int n,k,i;
	bool left=false;
	cin>>n>>k;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='T')
			left=true;
		if(s[i]=='G')
			break;
	}
	for(;i<n && i>=0;i+=k* (left?-1:1) )
		if(s[i]=='T')
		{
			cout<<"YES"<<endl;
			return 0;
		}
		else if(s[i]=='#')
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"NO"<<endl;
	return 0;
}