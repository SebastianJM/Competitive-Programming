#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi kmp(const string &s, const string &t)
{
	vi b(t.size() + 1, -1);
	for(int i = 1; i <= t.size(); i++)
	{
		int p = b[i - 1];
		while(p != -1 && t[p] != t[i - 1])
			p = b[p];
		b[i] = p + 1;
	}
	vi ans;
	for(int i = 0, p = 0; i < s.size(); i++)
	{
		while(p != -1 && (p == t.size() || t[p] != s[i]))
			p = b[p];
		p++;
		if(p == t.size())
			ans.push_back(i + 1 - t.size());
	}
	return ans;
}

int main() 
{
	string s;
	int t;
	bool first=true;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(!first)
			cout<<endl;
		first=false;
		int r = kmp(s + s, s).size(); 
		cout<<s.size()/(r-1)<<endl;
	}
	return 0;
}