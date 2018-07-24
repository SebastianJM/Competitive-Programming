#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	string s,a;
	cin>>s;
	map<string,int> mapa;
	for(int i=0;i<10;i++)
	{
		cin>>a;
		mapa[a]=i;
	}
	for(int i=0;i<8;i++)
		cout<<mapa[s.substr(i*10,10)];
	cout<<endl;

	return 0;
}