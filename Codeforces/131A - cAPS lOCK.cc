#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	if(s[0]>92)
	{
		for(int i=1;i<s.length();i++)
			if(s[i]>92)
			{
				cout<<s<<endl;
				return 0;
			}
		s[0]-=32;
		for(int i=1;i<s.length();i++)
			s[i]+=32;
		cout<<s<<endl;
	}
	else
	{
		for(int i=1;i<s.length();i++)
			if(s[i]>92)
			{
				cout<<s<<endl;
				return 0;
			}
		s[0]+=32;
		for(int i=1;i<s.length();i++)
			s[i]+=32;
		cout<<s<<endl;
	}
	return 0;
}
