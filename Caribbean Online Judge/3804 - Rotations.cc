#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,ac;
	unsigned int x;
	set<int> s;
	cin>>t;
	//cout<<__builtin_clz(t)<<endl;
	
	for(int i=0;i<t;i++)
	{
		cin>>x;
		//cout<<__builtin_clz(x)<<" //\n";
		s.clear();
		ac=0;
		for(int e=0;e<5;e++)
			if(x&(1<<e))
				ac|=(1<<e);
		//cout<<ac<<"\n";
		s.insert(ac);
		for(int e=5;e<32;e++)
		{
			ac>>=1;
			if(x&(1<<e))
				ac|=(1<<4);
			s.insert(ac);
			//cout<<ac<<"\n";
		}
		//cout<<"///"<<endl;
		for(int e=0;e<4;e++)
		{
			ac>>=1;
			if(x&(1<<e))
				ac|=(1<<4);
			s.insert(ac);
			//cout<<ac<<"\n";
		}
		if(s.size()==32)
			cout<<"yes\n";
		else
			cout<<"no\n";
		//cout<<s.size()<<endl;
	}
	return 0;
}