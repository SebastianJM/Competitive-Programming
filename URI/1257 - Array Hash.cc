#include <iostream>	
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int r=0,a=0;
		while(a<n)
		{
			cin>>s;
			for(int i=0;i<s.length();i++)
				r+=s[i]-'A'+a+i;			
			a++;
		}
		cout<<r<<endl;
	}
	return 0;
}