#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')
			s[i]='T';
		else if(s[i]=='T')
			s[i]='A';
		else if(s[i]=='C')
			s[i]='G';
		else
			s[i]='C';
	}
	for(int i=s.size()-1;i>=0;i--)
		cout<<s[i];
	return 0;
}