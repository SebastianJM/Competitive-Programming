#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;	
	int cont=0;
	char actual='1';
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==actual)
		{
			cont++;
			if(cont==7)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
		else
		{
			actual=s[i];
			cont=1;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}