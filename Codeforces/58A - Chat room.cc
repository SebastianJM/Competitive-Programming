#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	bool h,e,l1,l2,o;
	h=e=l1=l2=o=false;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='h')
		{
			h=true;
			continue;
		}
		if(h && s[i]=='e')
		{
			e=true;
			continue;
		}
		if(e && s[i]=='l')
		{
			if(l1)
			{
				l2=true;
				continue;
			}
			l1=true;
			continue;
		}
		if(l2 && s[i]=='o')
		{
			o=true;
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
		
	return 0;
}