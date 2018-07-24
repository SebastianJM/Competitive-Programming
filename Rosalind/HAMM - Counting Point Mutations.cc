#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int c=0;
	string s,x;
	cin>>s>>x;
	for(int i=0;i<s.size();i++)
		if(s[i]!=x[i])
			c++;
	cout<<c;
	return 0;
}