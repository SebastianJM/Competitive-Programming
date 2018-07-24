#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
	int inpares=0,vows=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			int n=s[i]-'0';
			if(n&1)
				inpares++;
		}
		else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		{
			vows++;
		}
	}
	cout<<inpares+vows<<endl;
	return 0;
}