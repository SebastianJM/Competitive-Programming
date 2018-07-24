#include <bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		int m=s.size()-1;
		if((s[m-1]=='c' && s[m]=='h')||s[m]=='x'||s[m]=='s'||s[m]=='o')
			s+="es";
		else if(s[m-1]=='f' && s[m]=='e')
		{
			s[m-1]='v';
			s+="s";
		}
		else if(s[m]=='f')
		{
			s[m]='v';
			s+="es";
		}
		else if(s[m]=='y')
		{
			s[m]='i';
			s+="es";
		}
		else
			s+="s";
		cout<<s<<endl;
	}
	return 0;
}