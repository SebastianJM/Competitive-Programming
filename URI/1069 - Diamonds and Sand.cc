#include <iostream>	
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,i,t;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		i=t=0;
		for(int e=0;e<s.length();e++)
		{
			if(s[e]=='<')
				i++;
			else if(s[e]=='>' && i>0)
			{
				t++;
				i--;
			}
		}
		cout<<t<<endl;
	}
	return 0;
}
