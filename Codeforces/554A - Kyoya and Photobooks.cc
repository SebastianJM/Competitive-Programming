#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
	cin>>s;
	cout<<(s.length()+1)*26-s.length();
    
    return 0;
}