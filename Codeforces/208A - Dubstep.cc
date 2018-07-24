#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin>>s;
	size_t pos=s.find("WUB");
	while(pos!=string::npos)
	{
		s[pos]=s[pos+1]=s[pos+2]='+';
		pos=s.find("WUB");
	}
	int con=0;
	int rep=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='+')
		{
			i+=2;
			if(con&&i<s.length()-1&&(!rep))
				cout<<" ";		
			rep=1;
			continue;
		}		
		cout<<s[i];
		con=1;
		rep=0;
	}

	return 0;
}