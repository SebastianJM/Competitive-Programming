#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin>>s;
	vector<int> vec=vector<int>(s.length()/2+1);
	int e=0;
	for(int i=0;i<s.length();i+=2)
	{
		vec[e]=s[i]-48;
		e++;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size()-1;i++)
		cout<<vec[i]<<'+';
	cout<<vec[vec.size()-1];
	return 0;
}