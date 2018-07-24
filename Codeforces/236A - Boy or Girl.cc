#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	vector<int> vec=vector<int>(26,0);
	cin>>s;
	for(int i=0;i<s.length();i++)
		vec[s[i]-97]++;
	int suma=0;
	for(int i=0;i<26;i++)
		if(vec[i]!=0)
			suma++;
	if(suma%2==1)
		cout<<"IGNORE HIM!";
	else
		cout<<"CHAT WITH HER!";
	return 0;
}