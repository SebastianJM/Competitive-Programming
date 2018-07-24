#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int up,down;
	up=down=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(isupper(s[i]))
			up++;
		else
			down++;
	}
	if(up>down)
		transform(s.begin(),s.end(),s.begin(),::toupper);
	else
		transform(s.begin(),s.end(),s.begin(),::tolower);
	cout<<s;

	return 0;
}
