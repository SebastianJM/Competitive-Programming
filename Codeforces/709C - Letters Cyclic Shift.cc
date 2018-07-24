#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
	bool inn=false;
	cin>>s;
	for(int i=0;i<s.length() && !inn;i++)
	{
		while(i<s.length() && s[i]!='a')
		{
			s[i]--;
			i++;
			inn=true;
		}
	}
	if(!inn)
		s[s.length()-1]='z';
	cout<<s;
	return 0;
}