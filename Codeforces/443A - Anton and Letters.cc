#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	vector<int> vec(26,0);
	while(cin>>s)
	{
	
	for(int i=0;i<s.length();i++)
	{
		if(isalpha(s[i]))
			vec[s[i]-97]++;
	}
	}
	cout<<26-count(vec.begin(),vec.end(),0);
	return 0;
}