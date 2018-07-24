#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string a,b;
	while(n--)
	{
		cin>>a>>b;
		string s;
		int m=min(a.length(),b.length()),cual;
		
		for(int i=0;i<m;i++)
		{
			s.push_back(a[i]);
			s.push_back(b[i]);
		}

		if(a.length()<b.length())
			for(int i=m;i<b.length();i++)
				s.push_back(b[i]);
		
		else if(b.length()<a.length())
			for(int i=m;i<a.length();i++)
				s.push_back(a[i]);
		cout<<s<<endl;
	}
	return 0;
}