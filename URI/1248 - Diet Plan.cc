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
	string a,b,c;
	cin>>n;
	getchar();
	while(n--)
	{
		vector<int> dieta(27,0);
		int dude=0;
		getline(cin,a);
		getline(cin,b);
		getline(cin,c);
		for(int i=0;i<a.length();i++)
			dieta[a[i]-'A']++;
		for(int i=0;i<b.length();i++)
			dieta[b[i]-'A']--;
		for(int i=0;i<c.length();i++)
			dieta[c[i]-'A']--;
		string s;
		for(int i=0;i<dieta.size();i++)
			if(dieta[i]<0)
			{
				cout<<"CHEATER"<<endl;
				dude=1;
				break;
			}
			else if(dieta[i]>0)
				s.push_back(i+'A');
		if(dude==0)
		{
			sort(s.begin(),s.end());
			cout<<s<<endl;
		}
	}

	return 0;
}