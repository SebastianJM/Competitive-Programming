#include <bits/stdc++.h>

using namespace std;

int main() 
{	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='T')
			s[i]='U';
	cout<<s<<endl;
	return 0;
}