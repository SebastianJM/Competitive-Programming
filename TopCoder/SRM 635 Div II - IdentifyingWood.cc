#include <bits/stdc++.h>

using namespace std;

class IdentifyingWood
{
	public:
		string check(string s, string t)
		{
			for(int i=0,j=0;j<s.size() && i<t.size();j++,i++)
			{
				while(i<t.size() && s[j]!=t[i])
					i++;
				if(j==s.size()-1 && s[j]==t[i])
					return "Yep, it's wood.";
				if(i==t.size())
					return "Nope.";
			}
			return "Nope.";
		}
};
