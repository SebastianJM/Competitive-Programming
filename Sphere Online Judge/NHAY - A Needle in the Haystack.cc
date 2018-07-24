#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
vi kmp(const string &s, const string &t) // Find t within s
{
 // Find borders of the string t
 vi b(t.size() + 1, -1);
 for(int i = 1; i <= t.size(); i++)
 {
 int p = b[i - 1];
 while(p != -1 && t[p] != t[i - 1])
 p = b[p];
 b[i] = p + 1;
 }
 // Find matches
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	vi ans;
	bool f=true;
	int n;
	while(cin>>n)
	{
		if(!f)
			cout<<"\n";
		f=false;
		cin>>a>>b;
		ans=kmp(b,a);
		for(int i=0;i<ans.size();i++)
		{
			if(i!=0)
				cout<<"\n";
			cout<<ans[i];
		}
	}
	return 0;
} 