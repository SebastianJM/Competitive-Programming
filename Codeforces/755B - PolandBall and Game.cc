#include <bits/stdc++.h>

using namespace std;

int main() 
{
	set<string> cad;
	string s;
	int p,e,a,b,r;
	a=b=r=0;
	cin>>p>>e;
	a=p;
	b=e;
	for(int i=0;i<p;i++)
	{
		cin>>s;
		cad.insert(s);
	}
	for(int i=0;i<e;i++)
	{
		cin>>s;
		if(cad.find(s)!=cad.end())
		{
			a--;
			b--;
			r++;
		}
	}
	if(b>a)
		cout<<"NO"<<endl;
	else if(a>b)
		cout<<"YES"<<endl;
	else
	{
		if(r&1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}