#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int main() 
{
	string s;
	long long ans=0,con=0;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='a')
		{
			ans=(ans+con)%MOD;
			con=(con*2)%MOD;
		}
		else
			con=(con+1)%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}