#include <iostream>
#include <string>

using namespace std;

bool Validacion(string s)
{
	for(int i=0;i<s.length();i++)
		if(s[i]=='D')
			return false;
	return true;
}
int main()
{
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(Validacion(s))
			cout<<"Possible"<<endl;
		else
			cout<<"You shall not pass!"<<endl;
	}
	return 0;
}