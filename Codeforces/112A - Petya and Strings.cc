#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string cad1,cad2;
	cin>>cad1;
	cin>>cad2;
	for(int i=0;i<cad1.length();i++)
	{
		if(cad1[i]!=cad2[i] && cad1[i]+32!=cad2[i] && cad2[i]+32!=cad1[i])
		{
			if(cad1[i]<96)
				cad1[i]+=32;
			if(cad2[i]<96)
				cad2[i]+=32;
			if(cad1[i]<cad2[i])
				cout<<"-1";
			else
				cout<<"1";
			return 0;
		}
	}
	cout<<"0";
	return 0;
}