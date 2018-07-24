#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,q,l,r;
	char a,b;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r>>a>>b;
		l--;r--;
	
		for(int z=l;z<=r;z++)
			if(s[z]==a)
				s[z]=b;
	}
	cout<<s<<endl;
	return 0;
	
}