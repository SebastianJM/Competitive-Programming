#include <bits/stdc++.h>
using namespace std;

int main() 
{
	map<char,unsigned long long> mp;
	mp['a']=4; mp['b']=5; mp['c']=6; mp['d']=3; mp['e']=2; mp['f']=1;
	char c;
	unsigned long long n,ans=0LL;
	cin>>n>>c;
	ans=((n-1)/4)*16+mp[c];
	if(n%4==0 || n%4==2)
		ans+=7;
	cout<<ans<<endl;
	
	return 0;
}