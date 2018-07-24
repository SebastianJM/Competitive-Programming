#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	bool AB,BA;
	AB=BA=false;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		{
			if(!AB && i+1<s.length() && s[i+1]=='B')
			{
				AB=true;
				i++;
			}
		}
		else if(s[i]=='B')
		{
			if(AB && !BA && i+1<s.length() && s[i+1]=='A')
			{
				BA=true;
				i++;
			}
		}
	}
	if(AB&&BA)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	AB=BA=false;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		{
			if(BA && !AB && i+1<s.length() && s[i+1]=='B')
			{
				AB=true;
				i++;
			}
		}
		else if(s[i]=='B')
		{
			if(!BA && i+1<s.length() && s[i+1]=='A')
			{
				BA=true;
				i++;
			}
		}
	}
	if(AB&&BA)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}