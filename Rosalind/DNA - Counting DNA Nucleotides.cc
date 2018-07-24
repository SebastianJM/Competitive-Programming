#include <bits/stdc++.h>

using namespace std;

int main() 
{	
	map<char,int> m;
	vector<int> v(4,0);
	string s;
	m['A']=0;
	m['C']=1;
	m['G']=2;
	m['T']=3;
	cin>>s;
	for(int i=0;i<s.size();i++)
		v[m[s[i]]]++;
	cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
	return 0;
}