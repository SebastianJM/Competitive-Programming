#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	string s,a;
	cin>>s;
	a=s.substr(s.size()>1?s.size()-2:s.size()-1,s.size()>1?2:1);
	int n=stoi(a);
	//cout<<n;
	if(n%4==0)
		cout<<4<<endl;
	else
		cout<<0<<endl;
	return 0;
}