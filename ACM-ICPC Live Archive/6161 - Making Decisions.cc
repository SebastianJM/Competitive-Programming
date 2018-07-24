#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(s[s.length()/2-1]!=s[s.length()/2])
			cout<<"Do-it-Not"<<endl;
		else
			cout<<"Do-it"<<endl;
			
	}
	return 0;
}