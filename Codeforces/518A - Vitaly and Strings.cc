#include <iostream>
#include <string>

using namespace std;

int main()
{
	int aux;
	string s,t;
	cin>>s>>t;
	aux=s.length()-1;
	while(t[aux]==97)
		aux--;
	t[aux]--;
	if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end()))
	{
		cout<<t;
		return 0;
	}
	t[aux]++;
	aux=s.length()-1;
	while(s[aux]==122)
		aux--;
	s[aux]++;
	if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end()))
	{
		cout<<s;
		return 0;
	}
	else
		cout<<"No such string";
	
	return 0;
}


