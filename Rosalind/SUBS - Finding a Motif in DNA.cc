#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s,t;
	vector<int> pos;
	cin>>s>>t;
	for(int i=0;i<s.size()-t.size();i++)
		if(s.substr(i,t.size())==t)
			pos.push_back(i+1);
	for(int i=0;i<pos.size();i++)
		cout<<pos[i]<<" ";
	return 0;
}