#include <iostream>
#include <string>

using namespace std;

string s;

bool Validar()
{
	if(s[0]!=s[1] && s[0]!=s[2] && s[0]!=s[3] && s[1]!=s[2] && s[1]!=s[3] && s[2]!=s[3])
		return true;
	return false;
}
int main()
{
	cin>>s;
	while(1)
	{		
		s[3]++;
		if(s[3]>57)
		{
			s[3]='0';
			s[2]++;
			if(s[2]>57)
			{
				s[2]='0';
				s[1]++;
				if(s[1]>57)
				{
					s[1]='0';
					s[0]++;
				}
			}
		}
		if(Validar())
		{
			cout<<s;
			return 0;
		}
	}
	return 0;
}
