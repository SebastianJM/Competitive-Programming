#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
	cin>>s;
	bool is=false;
	int c=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
			is=true;
		else
		{
			if(is)
				c++;
		}
	}
	if(is && c>=6)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}