#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;	
	int cont=0;
	for(int i=1;i<s.length();i++)
		if(s[i]==s[i-1])
			cont++;
	cout<<cont<<endl;
	return 0;
}